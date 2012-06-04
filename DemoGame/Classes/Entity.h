#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "Controller.h"

using namespace cocos2d;

class Entity :	public CCNode, 
				public ControllerListener
{
public:
	Entity();
	~Entity();

	virtual bool init(CCNode *parent);

	void SetVisual(CCSprite *sprite);
	void SetController(Controller *controller);

	virtual void UpdatePosition(float dt, float xDelta, float yDelta);
	virtual void TriggerPrimary();
	virtual void TriggerSecondary();


private:
	CCSprite* mSprite;


};

#endif  // __ENTITY_H__