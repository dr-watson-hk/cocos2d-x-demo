#include "BulletManager.h"
#include "Bullet.h"
#include "SoundManager.h"


BulletManager::BulletManager()
	: mBulletList(NULL)
	, mCurrentIndex(0)
	, mBulletListener(NULL)
{
}


BulletManager::~BulletManager()
{
	CC_SAFE_RELEASE(mBulletList);

}



BulletManager *BulletManager::initWithBatchNode(CCSpriteBatchNode *spriteBatch)
{
	BulletManager *manager = new BulletManager(); 
	if (manager && manager->init(spriteBatch)) 
	{
		manager->autorelease();
		return manager;

	}
	else
	{
		CC_SAFE_DELETE(manager);
		return NULL;
	}

	

}


bool BulletManager::init(CCSpriteBatchNode *spriteBatch)
{
	bool bRet = false;
    do 
    {
		CCNode *parentNode = spriteBatch->getParent();

		mBulletList = CCArray::arrayWithCapacity(MAX_BULLET);
		mBulletList->retain();

		for (int i=0;i<MAX_BULLET;i++)
		{
			Bullet *bullet = Bullet::bulletWithBatchNode(spriteBatch);
			bullet->SetActive(false);

			mBulletList->addObject(bullet);
			
			parentNode->addChild(bullet);

		}

		this->scheduleUpdate();

		bRet = true;

    } while (0);

    return bRet;

}


void BulletManager::update(ccTime dt)
{
	if (mBulletListener)
	{
		CCObject *obj = NULL;

		CCARRAY_FOREACH(mBulletList, (CCObject *)obj)
		{
			Bullet *bullet = (Bullet *) obj;
			if (bullet->IsActive() && mBulletListener->CollideWithBullet(bullet))
			{
				SoundManager::sharedSoundManager()->PlayHitSFX();
				bullet->SetActive(false);
			}
		}
	}

}


void BulletManager::SetBulletListener(BulletListener *listener)
{
	mBulletListener = listener;

}


void BulletManager::Shoot(const CCPoint &fromPosition)
{
	SoundManager::sharedSoundManager()->PlayLaserSFX();

	Bullet *bullet = (Bullet *)mBulletList->objectAtIndex(mCurrentIndex);
	bullet->SetPosition(fromPosition);
	bullet->SetActive(true);

	mCurrentIndex++;
	if (mCurrentIndex >= MAX_BULLET)
		mCurrentIndex = 0;

}


