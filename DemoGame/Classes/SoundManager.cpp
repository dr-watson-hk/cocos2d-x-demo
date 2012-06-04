#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "GameManager.h"
#include "SoundManager.h"

using namespace cocos2d;


SoundManager *SoundManager::mSharedSoundManager = NULL;


SoundManager *SoundManager::sharedSoundManager()
{
	if (mSharedSoundManager == NULL)
	{
		mSharedSoundManager = new SoundManager();
		if (!mSharedSoundManager || !mSharedSoundManager->init())
		{
			CC_SAFE_DELETE(mSharedSoundManager);
		}

	}

	return mSharedSoundManager;

}


void SoundManager::purgeSharedSoundManager()
{
    CC_SAFE_DELETE(mSharedSoundManager);

}


bool SoundManager::init()
{
	bool bRet = false;
    do 
    {
		CocosDenshion::SimpleAudioEngine *audioEngine = CocosDenshion::SimpleAudioEngine::sharedEngine();
		audioEngine->preloadBackgroundMusic("12thWarrior.mp3");

        bRet = true;

    } while (0);

    return bRet;
}



SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}


void SoundManager::PlayMusic()
{
	CocosDenshion::SimpleAudioEngine *audioEngine = CocosDenshion::SimpleAudioEngine::sharedEngine();
	audioEngine->playBackgroundMusic("12thWarrior.mp3");

}
	

void SoundManager::StopMusic()
{
	CocosDenshion::SimpleAudioEngine *audioEngine = CocosDenshion::SimpleAudioEngine::sharedEngine();
	audioEngine->stopBackgroundMusic();

}
