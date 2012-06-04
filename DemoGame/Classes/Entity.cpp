#include "System.h"

#include "Entity.h"



Entity::Entity()
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


void Entity::SetController(Controller *controller)
{
	this->addChild(controller);

	controller->SetControllerListener(this);

}


void Entity::UpdatePosition(float dt, float xDelta, float yDelta)
{
	if (mSprite)
	{
		CCPoint pos = mSprite->getPosition();

		pos.x += xDelta*dt;
		pos.y += yDelta*dt;

		pos = ccpClamp(pos, System::CCMakePoint(0,0), System::CCMakePoint(480, 320));

		mSprite->setPosition(pos);

	}

}


void Entity::TriggerPrimary()
{
}


void Entity::TriggerSecondary()
{
}
