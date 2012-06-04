#include "HelloWorldScene.h"
#include "System.h"

#include "SneakyInput\SneakyJoystick.h"
#include "SneakyInput\SneakyJoystickSkinnedBase.h"
#include "SneakyInput\SneakyButton.h"
#include "SneakyInput\SneakyButtonSkinnedBase.h"

#include "SneakyInputEx.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::node();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        HelloWorld *layer = HelloWorld::node();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        CCMenuItemImage *pCloseItem = CCMenuItemImage::itemWithNormalImage(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
        this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Hello World", "Arial", 24);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));

        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        CCSprite* pSprite = CCSprite::spriteWithFile("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);


		System::Init();
			
		CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();

        if (System::IsPad())
		{
			cache->addSpriteFramesWithFile("images-hd.plist", "images-hd.png");
		}
		else
		{
			CCDirector::sharedDirector()->enableRetinaDisplay(true);
			cache->addSpriteFramesWithFile("images.plist", "images.png");
		}

		SneakyJoystickSkinnedBase *joystickBase = SneakyInputEx::joystickSkinnedBase(CCRect(0, 0, 64, 64), "circleBig.png", "circleSmall.png");
	
		if (joystickBase)
		{
			joystickBase->setPosition(System::CCMakePoint(48, 48));

			//mJoystick = joystickBase->getJoystick();

			this->addChild(joystickBase);

		}


		SneakyButtonSkinnedBase *buttonBase = SneakyInputEx::buttonSkinnedBase(CCRect(0,0,32,32), "buttonBlue.png", "buttonOrange.png");
		
		if (buttonBase)
		{
			buttonBase->setPosition(System::CCMakePoint(480-48, 48));

			//mButton = buttonBase->getButton();	

			this->addChild(buttonBase);
		}



        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

