#ifndef __GAMEPLAY_LAYER_H__
#define __GAMEPLAY_LAYER_H__

#include "cocos2d.h"

class SneakyJoystick;
class SneakyButton;

class GameScenePlayLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    LAYER_NODE_FUNC(GameScenePlayLayer);

private:

	void TryParticle();
	

};

#endif  // __GAMEPLAY_LAYER_H__