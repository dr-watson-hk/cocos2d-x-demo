#include "GameMenu.h"
#include "System.h"
#include "GameManager.h"


using namespace cocos2d;

CCScene* GameMenu::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::node();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        GameMenu *layer = GameMenu::node();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameMenu::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());
   
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		CCSprite *bg = CCSprite::spriteWithSpriteFrameName("background.png");
		CC_BREAK_IF(!bg);

		bg->setPosition(System::PointMake(size.width/2, size.height/2));
		this->addChild(bg);
       
		CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Main Menu", "Arial", 30);
        CC_BREAK_IF(! pLabel);

		pLabel->setColor(ccORANGE);
		pLabel->setPosition(System::PointMake(size.width/2, size.height-50));

		this->addChild(pLabel);

        pLabel = CCLabelTTF::labelWithString("Play Game", "Arial", 24);
        CC_BREAK_IF(! pLabel);

		CCMenuItemLabel *pPlayItem = CCMenuItemLabel::itemWithLabel(
            pLabel,
            this,
            menu_selector(GameMenu::menuPlayCallback));

        CC_BREAK_IF(! pPlayItem);


		pPlayItem->setPosition(System::PointMake(size.width/2, size.height/2));

       
		CCMenu* pMenu = CCMenu::menuWithItems(pPlayItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        this->addChild(pMenu, 1);

        bRet = true;
    } while (0);

    return bRet;
}

void GameMenu::menuPlayCallback(CCObject* pSender)
{
    // "Play" menu item clicked
    GameManager::sharedGameManager()->runSceneWithId(GameManager::SCENE_PLAY);

}

