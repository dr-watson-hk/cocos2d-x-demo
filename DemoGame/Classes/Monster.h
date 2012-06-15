#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"

#include "Entity.h"

using namespace cocos2d;

#define LEFT_LIMIT		-50
#define RIGHT_LIMIT		550

class Monster : public Entity
{
public:
	Monster();
	~Monster();

	static Monster *monsterWithBatchNode(CCSpriteBatchNode *spriteBatch);

	bool init(CCSpriteBatchNode *spriteBatch);

	virtual void UpdatePosition(float dt, float xDelta, float yDelta);

private:
	

};

#endif
