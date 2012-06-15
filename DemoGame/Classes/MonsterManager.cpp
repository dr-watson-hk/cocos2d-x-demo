#include "cocos2d.h"

#include "System.h"
#include "GameManager.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "Entity.h"
#include "Constants.h"
#include "SoundManager.h"


using namespace cocos2d;


MonsterManager::MonsterManager()
	: mMonsterList(NULL)
	, mAttackingTarget(NULL)
	, mCollisionListener(NULL)
{

}


MonsterManager::~MonsterManager()
{
	CC_SAFE_RELEASE(mMonsterList);

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
		CCNode *parentNode = spriteBatch->getParent();

		mMonsterList = CCArray::arrayWithCapacity(MAX_MONSTER);
		mMonsterList->retain();

		for (int i=0;i<MAX_MONSTER;i++)
		{
			Monster *monster = Monster::monsterWithBatchNode(spriteBatch);
			monster->SetActive(false);

			mMonsterList->addObject(monster);
			
			parentNode->addChild(monster);

		}

		this->scheduleUpdate();

		mTimer = 0.0f;

		mCurrentIndex = 0;

		bRet = true;

    } while (0);

    return bRet;

}


void MonsterManager::update(ccTime dt)
{
	mTimer += dt;
	
	if (mTimer > SPAWN_TIME)
	{
		mTimer = 0;

		float y = 20+(float)(rand()%280);

		Monster *monster = (Monster *)mMonsterList->objectAtIndex(mCurrentIndex);
		monster->SetPosition(System::PointMake(RIGHT_LIMIT, y));
		monster->SetActive(true);

		mCurrentIndex++;
		if (mCurrentIndex >= MAX_MONSTER)
			mCurrentIndex = 0;

	}

	if (mAttackingTarget)
	{
		CCObject *obj = NULL;

		CCARRAY_FOREACH(mMonsterList, (CCObject *)obj)
		{
			Monster *monster = (Monster *) obj;
			if (monster->IsActive() && monster->CollidedWith(mAttackingTarget))
			{
				SoundManager::sharedSoundManager()->PlayHitSFX();
				if (mCollisionListener)
					mCollisionListener->CollisionDetected(monster, mAttackingTarget);

			}
		}
	}

}


void MonsterManager::SetAttackingTarget(Collidable *target)
{
	mAttackingTarget = target;

}


void MonsterManager::SetCollisionListener(CollisionListener *listener)
{
	mCollisionListener = listener;

}


bool MonsterManager::CollideWithBullet(Collidable *bullet)
{
	CCObject *obj = NULL;

	CCARRAY_FOREACH(mMonsterList, (CCObject *)obj)
	{
		Monster *monster = (Monster *) obj;
		if (monster->IsActive() && monster->CollidedWith(bullet))
		{
			CCNode *parent = this->getParent();
			CCParticleSystemQuad *m_emitter = (CCParticleSystemQuad *) parent->getChildByTag(TAB_PARTICLE);

			if (m_emitter && !m_emitter->getIsActive())
			{
				CCPoint pos = monster->GetPosition();

				m_emitter->resetSystem();
				m_emitter->setPosition(pos);

			}

			monster->SetActive(false);
			return true;

		}
	}

	return false;

}
