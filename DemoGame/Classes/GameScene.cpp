#include "System.h"

#include "GameScene.h"
#include "GameSceneBgLayer.h"
#include "GameScenePlayLayer.h"


using namespace cocos2d;

// on "init" you need to initialize your instance
bool GameScene::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCScene::init());

		//CocosDenshion::SimpleAudioEngine::sharedEngine();
		/*System::Init();
			
		CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();

        if (System::IsPad())
		{
			cache->addSpriteFramesWithFile("images-hd.plist", "images-hd.png");
		}
		else
		{
			CCDirector::sharedDirector()->enableRetinaDisplay(true);
			cache->addSpriteFramesWithFile("images.plist", "images.png");
		}*/

		// 'layer' is an autorelease object
        GameSceneBgLayer *bgLayer = GameSceneBgLayer::node();
        CC_BREAK_IF(! bgLayer);

		this->addChild(bgLayer);

		GameScenePlayLayer *playLayer = GameScenePlayLayer::node();
        CC_BREAK_IF(! playLayer);

		this->addChild(playLayer);

        bRet = true;

    } while (0);

    return bRet;
}


