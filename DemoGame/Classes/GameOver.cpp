#include "GameOver.h"
#include "System.h"
#include "GameManager.h"


using namespace cocos2d;

CCScene* GameOver::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::node();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        GameOver *layer = GameOver::node();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOver::init()
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

		CCSprite *girl = CCSprite::spriteWithSpriteFrameName("girl4.png");
		girl->setPosition(System::PointMake(110, 110));
		this->addChild(girl);

		CCLabelTTF* pLabel = CCLabelTTF::labelWithString("GAME OVER", "Arial", 30);
        CC_BREAK_IF(! pLabel);

		pLabel->setColor(ccRED);
		pLabel->setPosition(System::PointMake(size.width/2, size.height-50));

		this->addChild(pLabel);

        pLabel = CCLabelTTF::labelWithString("Retry", "Arial", 24);
        CC_BREAK_IF(! pLabel);

		CCMenuItemLabel *pRetryItem = CCMenuItemLabel::itemWithLabel(
            pLabel,
            this,
            menu_selector(GameOver::menuRetryCallback));

        CC_BREAK_IF(! pRetryItem);

		pRetryItem->setPosition(System::PointMake(size.width/2, size.height/2+20));

		pLabel = CCLabelTTF::labelWithString("Exit", "Arial", 24);
        CC_BREAK_IF(! pLabel);

		CCMenuItemLabel *pExitItem = CCMenuItemLabel::itemWithLabel(
            pLabel,
            this,
            menu_selector(GameOver::menuExitCallback));

        CC_BREAK_IF(! pExitItem);

		pExitItem->setPosition(System::PointMake(size.width/2, size.height/2-20));

       
		CCMenu* pMenu = CCMenu::menuWithItems(pRetryItem, pExitItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        this->addChild(pMenu, 1);

        bRet = true;
    } while (0);

    return bRet;
}

void GameOver::menuRetryCallback(CCObject* pSender)
{
    // "Retry" menu item clicked
    GameManager::sharedGameManager()->runSceneWithId(GameManager::SCENE_PLAY);

}


void GameOver::menuExitCallback(CCObject* pSender)
{
    // "Exit" menu item clicked
    GameManager::sharedGameManager()->runSceneWithId(GameManager::SCENE_MENU);

}

