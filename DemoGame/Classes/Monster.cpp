#include "System.h"

#include "Monster.h"
#include "SimpleMoveController.h"


Monster::Monster()
{
	

}

	
Monster::~Monster()
{
}


Monster *Monster::monsterWithBatchNode(CCSpriteBatchNode *spriteBatch)
{
	Monster *monster = new Monster(); 
	if (monster && monster->init(spriteBatch)) 
	{
		monster->autorelease();
		return monster;

	}
	else
	{
		CC_SAFE_DELETE(monster);
		return NULL;
	}

}


// on "init" you need to initialize your instance
bool Monster::init(CCSpriteBatchNode *spriteBatch)
{
    bool bRet = false;
    do 
    {
		CCNode *parent = spriteBatch->getParent();

		//////////////////////////////////////////////////////////////////////////
        // super init first
        //

        CC_BREAK_IF(! Entity::init(parent));

		//////////////////////////////////////////////////////////////////////////
		// add visual component
		//
		CCSprite *sprite = CCSprite::spriteWithSpriteFrameName("enemyBug.png");
		CC_BREAK_IF (!sprite);

		sprite->setFlipX(true);
		sprite->setPosition(System::PointMake(RIGHT_LIMIT, 160));
		spriteBatch->addChild(sprite);

		SetVisual(sprite);

		//////////////////////////////////////////////////////////////////////////
		// add control component
		//
		SimpleMoveController *controller = SimpleMoveController::controllerWithParentNode(parent);
		CC_BREAK_IF (!controller);

		float speed = -(80+(float)(rand()%20));
		controller->SetSpeed(speed);

		SetController(controller);

		SetRadius(System::GetRealSize(35));

		bRet = true;

    } while (0);

    return bRet;
}


void Monster::UpdatePosition(float dt, float xDelta, float yDelta)
{
	
	Entity::UpdatePosition(dt, xDelta, yDelta);

	CCPoint pos = GetPosition();

	if (pos.x < LEFT_LIMIT)
		SetActive(false);

}