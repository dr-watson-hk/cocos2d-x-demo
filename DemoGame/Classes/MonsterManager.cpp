#include "cocos2d.h"


#include "GameManager.h"
#include "MonsterManager.h"

using namespace cocos2d;




MonsterManager::MonsterManager()
{
}


MonsterManager::~MonsterManager()
{
}




MonsterManager *MonsterManager::initWithBatchNode(CCSpriteBatchNode *spriteBatch)
{
	MonsterManager *manager = new MonsterManager(); 
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


bool MonsterManager::init(CCSpriteBatchNode *spriteBatch)
{
	bool bRet = false;
    do 
    {


		bRet = true;

    } while (0);

    return bRet;

}
