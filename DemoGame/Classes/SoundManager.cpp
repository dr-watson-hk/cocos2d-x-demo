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
		audioEngine->preloadBackgroundMusic("music.mp3");

		audioEngine->preloadEffect("laser.wav");
		audioEngine->preloadEffect("hit.wav");

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
	audioEngine->playBackgroundMusic("music.mp3", true);

}
	

void SoundManager::StopMusic()
{
	CocosDenshion::SimpleAudioEngine *audioEngine = CocosDenshion::SimpleAudioEngine::sharedEngine();
	audioEngine->stopBackgroundMusic();

}


void SoundManager::PlayLaserSFX()
{
	CocosDenshion::SimpleAudioEngine *audioEngine = CocosDenshion::SimpleAudioEngine::sharedEngine();
	audioEngine->playEffect("laser.wav");

}
	

void SoundManager::PlayHitSFX()
{
	CocosDenshion::SimpleAudioEngine *audioEngine = CocosDenshion::SimpleAudioEngine::sharedEngine();
	audioEngine->playEffect("hit.wav");

}

