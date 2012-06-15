#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

#include "Controller.h"
#include "Collision.h"

using namespace cocos2d;


class Entity :	public CCNode, 
				public ControllerListener,
				public Collidable
{
public:
	Entity();
	~Entity();

	virtual bool init(CCNode *parent);

	void SetVisual(CCSprite *sprite);
	void SetController(Controller *controller);

	void SetRadius(float radius);

	void SetPosition(const CCPoint &point);

	void SetActive(bool flag);
	bool IsActive();

	// ControllerListener
	virtual void UpdatePosition(float dt, float xDelta, float yDelta);
	virtual void FirePrimary();
	virtual void FireSecondary();

	// Collidable
	virtual bool CollidedWith(Collidable *target);
	virtual const CCPoint& GetPosition();
	virtual float GetRadius();

private:
	bool mActive;
	CCSprite* mSprite;
	float mRadius;
	Controller *mController;

};

#endif  // __ENTITY_H__