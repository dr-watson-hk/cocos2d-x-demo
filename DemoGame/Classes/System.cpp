#include "System.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "Foundation/Foundation.h"
#endif


bool System::mIsPad = false;


void System::Init()
{
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    mIsPad = UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad;
#else
    mIsPad = false;
#endif
    
}


CCPoint System::CCMakePoint(float x, float y)
{
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (mIsPad)
        return ccp(x*2+32, y*2+64);
    else 
#endif
        return ccp(x, y);

}


bool System::IsPad()
{
    return  mIsPad;

}
