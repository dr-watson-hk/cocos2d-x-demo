#include "SimpleMoveController.h"

#include "System.h"


SimpleMoveController::SimpleMoveController()
{
}

	
SimpleMoveController::~SimpleMoveController()
{
}


SimpleMoveController *SimpleMoveController::controllerWithParentNode(CCNode *parent)
{
	SimpleMoveController *controller = new SimpleMoveController(); 
	if (controller && controller->init(parent)) 
	{
		controller->autorelease();
		return controller;

	}
	else
	{
		CC_SAFE_DELETE(controller);
		return NULL;
	}

	

}


// on "init" you need to initialize your instance
bool SimpleMoveController::init(CCNode *parent)
{
    bool bRet = false;
    do 
    {
		//////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! Controller::init());

		mSpeed = 0;

		bRet = true;

    } while (0);

    return bRet;
}



void SimpleMoveController::update(ccTime dt)
{
	
	if (mListener)
	{
		mListener->UpdatePosition(dt, mSpeed, 0.0f);

	}

}


void SimpleMoveController::SetSpeed(float speed)
{
	mSpeed = speed;

}