#include "cocos2d.h"


#include "BulletManager.h"



BulletManager::BulletManager()
{
}


BulletManager::~BulletManager()
{
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


		bRet = true;

    } while (0);

    return bRet;

}
