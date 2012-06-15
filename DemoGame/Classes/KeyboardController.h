#ifndef __KEYBOARD_CONTROLLER_H__
#define __KEYBOARD_CONTROLLER_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include "cocos2d.h"

using namespace cocos2d;

#include "Controller.h"


class KeyboardController : public Controller
{
public:
	KeyboardController();
	~KeyboardController();

	static KeyboardController *controllerWithParentNode(CCNode *parent);

	bool init(CCNode *parent);

	virtual void update(ccTime dt);

private:

	float mMovingSpeed;

	bool mFireKeyDown;

};


#endif


#endif

