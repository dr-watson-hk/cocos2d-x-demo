#ifndef __GAMEPLAY_LAYER_H__
#define __GAMEPLAY_LAYER_H__

#include "cocos2d.h"
#include "Collision.h"


class MonsterManager;
class BulletManager;

class GameScenePlayLayer :	public cocos2d::CCLayer, public CollisionListener
{
public:
	GameScenePlayLayer();
	~GameScenePlayLayer();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    LAYER_NODE_FUNC(GameScenePlayLayer);

	// CollisionListener
	virtual void CollisionDetected(Collidable *source, Collidable *target);


private:

	void AddParticle();
	
	MonsterManager *mMonsterManager;
	BulletManager *mBulletManager;

};

#endif  // __GAMEPLAY_LAYER_H__