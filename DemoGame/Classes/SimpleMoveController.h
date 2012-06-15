#ifndef __SIMPLE_MOVE_CONTROLLER_H__
#define __SIMPLE_MOVE_CONTROLLER_H__

#include "cocos2d.h"

using namespace cocos2d;

#include "Controller.h"


class SimpleMoveController : public Controller
{
public:
	SimpleMoveController();
	~SimpleMoveController();

	static SimpleMoveController *controllerWithParentNode(CCNode *parent);

	bool init(CCNode *parent);

	virtual void update(ccTime dt);

	void SetSpeed(float speed);


private:

	float mSpeed;

};

#endif

