#include "KeyboardController.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

KeyboardController::KeyboardController()
{
}

	
KeyboardController::~KeyboardController()
{
}


KeyboardController *KeyboardController::controllerWithParentNode(CCNode *parent)
{
	KeyboardController *controller = new KeyboardController(); 
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
bool KeyboardController::init(CCNode *parent)
{
    bool bRet = false;
    do 
    {
		//////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! Controller::init());

		mMovingSpeed = 150;
		mFireKeyDown = false;

		bRet = true;

    } while (0);

    return bRet;
}



void KeyboardController::update(ccTime dt)
{

	if (mListener)
	{
		float xDelta = 0;
		float yDelta = 0;

		if ((GetAsyncKeyState(VK_LEFT) & 0x8000)==0x8000)
			xDelta = -mMovingSpeed;

		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)==0x8000)
			xDelta = mMovingSpeed;

		if ((GetAsyncKeyState(VK_UP) & 0x8000)==0x8000)
			yDelta = mMovingSpeed;

		if ((GetAsyncKeyState(VK_DOWN) & 0x8000)==0x8000)
			yDelta = -mMovingSpeed;

		mListener->UpdatePosition(dt, xDelta, yDelta);


		if ((GetAsyncKeyState(VK_LCONTROL) & 0x8000)==0x8000)
		{
			if (!mFireKeyDown)
			{
				mFireKeyDown = true;
				mListener->FirePrimary();
			}
		}
		else
			mFireKeyDown = false;

	}

}

#endif

