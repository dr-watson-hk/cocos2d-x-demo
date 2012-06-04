#ifndef __BULLET_MANAGER_H__
#define __BULLET_MANAGER_H__

#include "cocos2d.h"

using namespace cocos2d;

class BulletManager : public CCNode
{
public:

	BulletManager();
	~BulletManager();

	static BulletManager *initWithBatchNode(CCSpriteBatchNode *spriteBatch);
	
	bool init(CCSpriteBatchNode *spriteBatch);


private:
	

};


#endif

