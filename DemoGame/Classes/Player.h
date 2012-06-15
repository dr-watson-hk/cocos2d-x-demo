#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

#include "Entity.h"

using namespace cocos2d;

class Shooter;


class Player : public Entity
{
public:
	Player();
	~Player();

	static Player *playerWithBatchNode(CCSpriteBatchNode *spriteBatch);

	bool init(CCSpriteBatchNode *spriteBatch);

	virtual void UpdatePosition(float dt, float xDelta, float yDelta);
	virtual void FirePrimary();

	void SetShooter(Shooter *shooter);

private:
	Shooter *mShooter;
};

#endif