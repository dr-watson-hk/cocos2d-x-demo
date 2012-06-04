#include "System.h"

#include "GameSceneBgLayer.h"

using namespace cocos2d;

// on "init" you need to initialize your instance
bool GameSceneBgLayer::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());
      
		CCSprite* pSprite = CCSprite::spriteWithSpriteFrameName("background.png");
		pSprite->setPosition(System::CCMakePoint(240, 160));
		this->addChild(pSprite);

        bRet = true;

    } while (0);

    return bRet;
}


