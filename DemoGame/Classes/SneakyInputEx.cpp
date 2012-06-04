#include "SneakyInput\SneakyJoystick.h"
#include "SneakyInput\SneakyJoystickSkinnedBase.h"
#include "SneakyInput\SneakyButton.h"
#include "SneakyInput\SneakyButtonSkinnedBase.h"

#include "SneakyInputEx.h"


SneakyJoystickSkinnedBase *SneakyInputEx::joystickSkinnedBase(CCRect padRect, const char *bgSprite, const char *thumbSprite)
{
	SneakyJoystickSkinnedBase *joystickBase = new SneakyJoystickSkinnedBase();

	if (joystickBase)
	{
		joystickBase->autorelease();
		joystickBase->init();
		joystickBase->setBackgroundSprite(CCSprite::spriteWithSpriteFrameName(bgSprite));
		joystickBase->setThumbSprite(CCSprite::spriteWithSpriteFrameName(thumbSprite));
	
		SneakyJoystick *joystick = new SneakyJoystick();
		
		if (joystick)
		{
			joystick->autorelease();
			joystick->initWithRect(padRect);

			joystickBase->setJoystick(joystick);

			return joystickBase;
		}

		joystickBase->release();

	}

	return NULL;

}

    
SneakyButtonSkinnedBase *SneakyInputEx::buttonSkinnedBase(CCRect btnRect, const char *upSprite, const char *downSprite)
{
	SneakyButtonSkinnedBase *buttonBase = new SneakyButtonSkinnedBase();

	if (buttonBase)
	{
		buttonBase->autorelease();
		buttonBase->init();
		buttonBase->setDefaultSprite(CCSprite::spriteWithSpriteFrameName(upSprite));
		buttonBase->setActivatedSprite(CCSprite::spriteWithSpriteFrameName(downSprite));
		buttonBase->setPressSprite(CCSprite::spriteWithSpriteFrameName(downSprite));

		SneakyButton *button = new SneakyButton();

		if (button)
		{
			button->autorelease();
			button->initWithRect(btnRect);
			button->setIsToggleable(false);
			button->setIsHoldable(true);

			buttonBase->setButton(button);

			return buttonBase;

		}

		buttonBase->release();
	
	}

	return NULL;

}
