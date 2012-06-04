#ifndef __SNEAKY_INPUT_EX_H__
#define __SNEAKY_INPUT_EX_H__

#include "cocos2d.h"

using namespace cocos2d;

class SneakyJoystickSkinnedBase;
class SneakyButtonSkinnedBase;

class SneakyInputEx
{
    
public:
    static SneakyJoystickSkinnedBase *joystickSkinnedBase(CCRect padRect, const char *bgSprite, const char *thumbSprite);
    static SneakyButtonSkinnedBase *buttonSkinnedBase(CCRect btnRect, const char *upSprite, const char *downSprite);
    
};

#endif
