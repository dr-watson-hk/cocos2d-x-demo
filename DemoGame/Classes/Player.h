#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

#include "Entity.h"

using namespace cocos2d;

class Player : public Entity
{
public:
	Player();
	~Player();

	static Player *playerWithBatchNode(CCSpriteBatchNode *spriteBatch);

	bool init(CCSpriteBatchNode *spriteBatch);

private:
	CCSprite *mHeart;

};

#endif  // __PLAYER_H__