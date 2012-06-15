#ifndef __BULLET_MANAGER_H__
#define __BULLET_MANAGER_H__

#include "cocos2d.h"

#include "Collision.h"


using namespace cocos2d;

#define MAX_BULLET			100

class BulletListener
{
public:
	virtual bool CollideWithBullet(Collidable *bullet) = 0;

};


class Shooter
{
public:
	virtual void Shoot(const CCPoint &fromPosition) = 0;

};


class BulletManager : public CCNode, public Shooter
{
public:

	BulletManager();
	~BulletManager();

	static BulletManager *initWithBatchNode(CCSpriteBatchNode *spriteBatch);
	
	bool init(CCSpriteBatchNode *spriteBatch);

	virtual void update(ccTime dt);

	void SetBulletListener(BulletListener *listener);

	// Shooter
	virtual void Shoot(const CCPoint &fromPosition);

private:
	
	CCArray *mBulletList;
	int mCurrentIndex;

	BulletListener *mBulletListener;

};


#endif

