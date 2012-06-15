#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

#include "Entity.h"

using namespace cocos2d;

#define BULLET_RIGHT_LIMIT			520

class Bullet : public Entity
{
public:
	Bullet();
	~Bullet();

	static Bullet *bulletWithBatchNode(CCSpriteBatchNode *spriteBatch);

	bool init(CCSpriteBatchNode *spriteBatch);

	virtual void UpdatePosition(float dt, float xDelta, float yDelta);

private:
	

};

#endif
