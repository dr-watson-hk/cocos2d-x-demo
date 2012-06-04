#include "SneakyInput\SneakyJoystick.h"
#include "SneakyInput\SneakyJoystickSkinnedBase.h"
#include "SneakyInput\SneakyButton.h"
#include "SneakyInput\SneakyButtonSkinnedBase.h"

#include "JoystickController.h"

#include "SneakyInputEx.h"
#include "System.h"


JoystickController::JoystickController()
{
}

	
JoystickController::~JoystickController()
{
}


JoystickController *JoystickController::joystickWithParentNode(CCNode *parent)
{
	JoystickController *controller = new JoystickController(); 
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
bool JoystickController::init(CCNode *parent)
{
    bool bRet = false;
    do 
    {
		//////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! Controller::init());

		SneakyJoystickSkinnedBase *joystickBase = SneakyInputEx::joystickSkinnedBase(CCRect(0, 0, 64, 64), "circleBig.png", "circleSmall.png");
	
		if (joystickBase)
		{
			joystickBase->setPosition(System::CCMakePoint(48, 48));

			mJoystick = joystickBase->getJoystick();

			parent->addChild(joystickBase);

		}


		SneakyButtonSkinnedBase *buttonBase = SneakyInputEx::buttonSkinnedBase(CCRect(0,0,32,32), "buttonBlue.png", "buttonOrange.png");
		
		if (buttonBase)
		{
			buttonBase->setPosition(System::CCMakePoint(480-48, 48));

			mButton = buttonBase->getButton();	

			parent->addChild(buttonBase);
		}

		
		bRet = true;

    } while (0);

    return bRet;
}



void JoystickController::update(ccTime dt)
{
	
	if (mListener)
	{
		CCPoint scaledV = ccpMult(mJoystick->getVelocity(), 480);
		
		mListener->UpdatePosition(dt, scaledV.x, scaledV.y);

	}

}
