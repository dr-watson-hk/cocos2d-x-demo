#ifndef __MONSTER_MANAGER_H__
#define __MONSTER_MANAGER_H__

#include "cocos2d.h"

using namespace cocos2d;


class MonsterManager: public CCNode
{
public:

	MonsterManager();
	~MonsterManager();

	static MonsterManager *initWithBatchNode(CCSpriteBatchNode *spriteBatch);
	
	bool init(CCSpriteBatchNode *spriteBatch);
	

private:
	

};


#endif

