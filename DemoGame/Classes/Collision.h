#ifndef __COLLISION_H__
#define __COLLISION_H__

#include "cocos2d.h"

class Collidable
{
public:
	virtual bool CollidedWith(Collidable *target) = 0;
	virtual const cocos2d::CCPoint& GetPosition() = 0;
	virtual float GetRadius() = 0;

};


class CollisionListener
{
public:
	virtual void CollisionDetected(Collidable *source, Collidable *target) = 0;
};


#endif
