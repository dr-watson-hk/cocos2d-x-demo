#include "System.h"

#include "Entity.h"



Entity::Entity()
	: mSprite(NULL)
	, mController(NULL)
	, mActive(true)
	, mRadius(1.0f)
{
	mSprite = NULL;

}

	
Entity::~Entity()
{
}


// on "init" you need to initialize your instance
bool Entity::init(CCNode *parent)
{
    bool bRet = false;
    do 
    {
		//parent->addChild(this);
		
		bRet = true;


    } while (0);

    return bRet;
}



void Entity::SetVisual(CCSprite *sprite)
{
	mSprite = sprite;

}


void Entity::SetActive(bool flag)
{
	mActive = flag;

	if (mSprite)
		mSprite->setIsVisible(flag);

	if (mActive)
	{
		if (mController)
			mController->scheduleUpdate();

	}
	else
	{
		if (mController)
			mController->unscheduleUpdate();

	}
}

	
bool Entity::IsActive()
{
	return mActive;

}


void Entity::SetController(Controller *controller)
{
	this->addChild(controller);

	controller->SetControllerListener(this);

	mController = controller;

}


const CCPoint& Entity::GetPosition()
{
	if (mSprite)
		return mSprite->getPosition();

	return CCPointZero;

}


void Entity::SetPosition(const CCPoint &point)
{
	if (mSprite)
		mSprite->setPosition(point);

}


void Entity::SetRadius(float radius)
{
	mRadius = radius;

}


float Entity::GetRadius()
{
	return mRadius;

}


bool Entity::CollidedWith(Collidable *target)
{
	if (mSprite)
	{
		CCPoint targetPos = target->GetPosition();
		float targetRadius = target->GetRadius();

		CCPoint pos = GetPosition();

		float dx = pos.x - targetPos.x;
		float dy = pos.y - targetPos.y;
		float radiusSum = mRadius + targetRadius;

		if ((dx*dx) + (dy*dy) < radiusSum*radiusSum) 
			return true;
		
	}

	return false;

}


void Entity::UpdatePosition(float dt, float xDelta, float yDelta)
{
	if (mSprite)
	{
		CCPoint pos = mSprite->getPosition();

		pos.x += xDelta*dt;
		pos.y += yDelta*dt;

		mSprite->setPosition(pos);

	}

}


void Entity::FirePrimary()
{
}


void Entity::FireSecondary()
{
}
