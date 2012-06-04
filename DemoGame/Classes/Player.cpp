#include "System.h"

#include "Player.h"
#include "JoystickController.h"


Player::Player()
{
	mHeart = NULL;

}

	
Player::~Player()
{
}


Player *Player::playerWithBatchNode(CCSpriteBatchNode *spriteBatch)
{
	Player *player = new Player(); 
	if (player && player->init(spriteBatch)) 
	{
		player->autorelease();
		return player;

	}
	else
	{
		CC_SAFE_DELETE(player);
		return NULL;
	}

	

}


// on "init" you need to initialize your instance
bool Player::init(CCSpriteBatchNode *spriteBatch)
{
    bool bRet = false;
    do 
    {
		CCNode *parent = spriteBatch->getParent();

		//////////////////////////////////////////////////////////////////////////
        // super init first
        //

        CC_BREAK_IF(! Entity::init(parent));

		//////////////////////////////////////////////////////////////////////////
		// add visual component
		//
		CCSprite *sprite = CCSprite::spriteWithSpriteFrameName("beetleship.png");
		CC_BREAK_IF (!sprite);

		sprite->setPosition(System::CCMakePoint(240, 160));
		spriteBatch->addChild(sprite);

		SetVisual(sprite);

		//////////////////////////////////////////////////////////////////////////
		// add control component
		//
		JoystickController *joystick = JoystickController::joystickWithParentNode(parent);
		CC_BREAK_IF (!joystick);

		SetController(joystick);

		//////////////////////////////////////////////////////////////////////////
		// add an extra image
		//
		mHeart = CCSprite::spriteWithSpriteFrameName("healthheart.png");
		mHeart->setPosition(System::CCMakePoint(240+100, 160+50));
		mHeart->setIsVisible(false);
		
		spriteBatch->addChild(mHeart); 

		bRet = true;

    } while (0);

    return bRet;
}

