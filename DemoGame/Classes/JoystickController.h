#ifndef __JOYSTICK_CONTROLLER_H__
#define __JOYSTICK_CONTROLLER_H__

#include "cocos2d.h"

using namespace cocos2d;

#include "Controller.h"

class SneakyJoystick;
class SneakyButton;


class JoystickController : public Controller
{
public:
	JoystickController();
	~JoystickController();

	static JoystickController *controllerWithParentNode(CCNode *parent);

	bool init(CCNode *parent);

	virtual void update(ccTime dt);

private:

	SneakyJoystick *mJoystick;
	SneakyButton *mButton;

	bool mButtonDown;

};

#endif

