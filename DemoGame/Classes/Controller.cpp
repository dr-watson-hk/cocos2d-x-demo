#include "Controller.h"

Controller::Controller()
{
	mListener = NULL;

}

Controller::~Controller()
{
}


// on "init" you need to initialize your instance
bool Controller::init()
{
    bool bRet = false;
    do 
    {
		this->scheduleUpdate();

		bRet = true;


    } while (0);

    return bRet;
}


void Controller::SetControllerListener(ControllerListener *listener)
{
	mListener = listener;

}
