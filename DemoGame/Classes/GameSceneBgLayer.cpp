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

		mX1 = 240;
		mX2 = mX1 + 511;

		mSpeed = 60;
      
		mBg1 = CCSprite::spriteWithSpriteFrameName("background.png");
		CC_BREAK_IF(!mBg1);

		mBg1->setPosition(System::PointMake(mX1, 160));
		this->addChild(mBg1);

		mBg2 = CCSprite::spriteWithSpriteFrameName("background.png");
		CC_BREAK_IF(!mBg2);

		mBg2->setPosition(System::PointMake(mX2, 160));
		mBg2->setFlipX(true);
		this->addChild(mBg2);

		this->scheduleUpdate();

        bRet = true;

    } while (0);

    return bRet;
}


void GameSceneBgLayer::update(ccTime dt)
{
	mX1 -= dt*mSpeed;
	mX2 -= dt*mSpeed;

	if (mX1 < -256)
	{
		mX1 = mX2 + 511;
	}

	if (mX2 < -256)
	{
		mX2 = mX1 + 511;
	}

	CCPoint pos = mBg1->getPosition();
	pos.x = mX1;
	mBg1->setPosition(pos);

	pos = mBg2->getPosition();
	pos.x = mX2;
	mBg2->setPosition(pos);

}
