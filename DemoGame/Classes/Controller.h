#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "cocos2d.h"

using namespace cocos2d;


class ControllerListener
{
public:
	virtual void UpdatePosition(float dt, float xDelta, float yDelta) = 0;
	virtual void FirePrimary() = 0;
	virtual void FireSecondary() = 0;

};


class Controller : public CCNode
{
public:
	Controller();
	~Controller();

	virtual bool init();

	void SetControllerListener(ControllerListener *listener);

protected:

	ControllerListener *mListener;

};

#endif

