#include "System.h"

#include "Player.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "KeyboardController.h"
#else
#include "JoystickController.h"
#endif

#include "BulletManager.h"


Player::Player()
	: mShooter(NULL)
{
	

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

		sprite->setPosition(System::PointMake(80, 160));
		spriteBatch->addChild(sprite);

		SetVisual(sprite);

		//////////////////////////////////////////////////////////////////////////
		// add control component
		//

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		KeyboardController *controller = KeyboardController::controllerWithParentNode(parent);
#else
		JoystickController *controller = JoystickController::controllerWithParentNode(parent);
#endif

		CC_BREAK_IF (!controller);

		SetController(controller);

		SetRadius(System::GetRealSize(50));

		bRet = true;

    } while (0);

    return bRet;
}


void Player::UpdatePosition(float dt, float xDelta, float yDelta)
{
	Entity::UpdatePosition(dt, xDelta, yDelta);

	CCPoint pos = GetPosition();

	pos = ccpClamp(pos, System::PointMake(0,0), System::PointMake(480, 320));

	SetPosition(pos);

}


void Player::FirePrimary()
{
	if (mShooter)
	{
		CCPoint pos = GetPosition();

		pos.x += System::GetRealSize(100);

		mShooter->Shoot(pos);

	}

}


void Player::SetShooter(Shooter *shooter)
{
	mShooter = shooter;

}
