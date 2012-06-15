#ifndef __BG_LAYER_H__
#define __BG_LAYER_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

class GameSceneBgLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    LAYER_NODE_FUNC(GameSceneBgLayer);

	virtual void update(ccTime dt);

private:

	CCSprite* mBg1;
	CCSprite* mBg2;

	float mX1;
	float mX2;
	float mSpeed;



};

#endif  // __BG_LAYER_H__