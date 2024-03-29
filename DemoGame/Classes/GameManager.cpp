#include "cocos2d.h"


#include "System.h"

#include "SoundManager.h"

#include "GameManager.h"
#include "GameScene.h"
#include "GameMenu.h"
#include "GameOver.h"


using namespace cocos2d;


GameManager *GameManager::mSharedGameManager = NULL;


GameManager *GameManager::sharedGameManager()
{
	if (mSharedGameManager == NULL)
	{
		mSharedGameManager = new GameManager();
		if (!mSharedGameManager || !mSharedGameManager->init())
		{
			CC_SAFE_DELETE(mSharedGameManager);
		}

	}

	return mSharedGameManager;

}


void GameManager::purgeSharedGameManager()
{
    CC_SAFE_DELETE(mSharedGameManager);

}


bool GameManager::init()
{
	bool bRet = false;
    do 
    {
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

        bRet = true;

    } while (0);

    return bRet;
}



GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}


void GameManager::runSceneWithId(SceneId id)
{

	CCScene *newScene = NULL;

	switch (id)
	{
	case SCENE_MENU:
		SoundManager::sharedSoundManager()->StopMusic();
		newScene = GameMenu::scene();
		break;

	case SCENE_PLAY:
		SoundManager::sharedSoundManager()->PlayMusic();
		newScene = GameScene::node();
		break;

	case SCENE_GAMEOVER:
		newScene = GameOver::scene();
		break;
	
	}

	if (newScene)
	{
		if (CCDirector::sharedDirector()->getRunningScene() == NULL)
			CCDirector::sharedDirector()->runWithScene(newScene);
		else
			CCDirector::sharedDirector()->replaceScene(newScene);

	}

}


