#include "System.h"

#include "Bullet.h"
#include "SimpleMoveController.h"


Bullet::Bullet()
{
}

	
Bullet::~Bullet()
{
}


Bullet *Bullet::bulletWithBatchNode(CCSpriteBatchNode *spriteBatch)
{
	Bullet *bullet = new Bullet(); 
	if (bullet && bullet->init(spriteBatch)) 
	{
		bullet->autorelease();
		return bullet;

	}
	else
	{
		CC_SAFE_DELETE(bullet);
		return NULL;
	}

}


// on "init" you need to initialize your instance
bool Bullet::init(CCSpriteBatchNode *spriteBatch)
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
		CCSprite *sprite = CCSprite::spriteWithSpriteFrameName("gemGreen.png");
		CC_BREAK_IF (!sprite);

		spriteBatch->addChild(sprite);

		SetVisual(sprite);

		//////////////////////////////////////////////////////////////////////////
		// add control component
		//
		SimpleMoveController *controller = SimpleMoveController::controllerWithParentNode(parent);
		CC_BREAK_IF (!controller);

		float speed = 200;
		controller->SetSpeed(speed);

		SetController(controller);

		SetRadius(System::GetRealSize(15));

		bRet = true;

    } while (0);

    return bRet;
}


void Bullet::UpdatePosition(float dt, float xDelta, float yDelta)
{
	
	Entity::UpdatePosition(dt, xDelta, yDelta);

	CCPoint pos = GetPosition();

	if (pos.x > BULLET_RIGHT_LIMIT)
		SetActive(false);

}
