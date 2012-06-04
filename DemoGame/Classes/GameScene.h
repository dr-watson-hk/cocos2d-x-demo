#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"


class GameScene : public cocos2d::CCScene
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
  
    // implement the "static node()" method manually
    LAYER_NODE_FUNC(GameScene);
};

#endif  // __GAMEPLAY_LAYER_H__