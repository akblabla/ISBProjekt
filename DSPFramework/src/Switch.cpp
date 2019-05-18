///////////////////////////////////////////////////////////
//  Switch.cpp
//  Implementation of Switch
//  Created on:      06-aug-2014 09:30:58
//  Original author: kbe
///////////////////////////////////////////////////////////
#include "Controller.h"

// Controller reference
Controller *pCtrl;

void InitSwitch(Controller *ctrl)
{
	pCtrl = ctrl;
}

extern "C" {

    void PressedSwitch(short sw)
    {
    	pCtrl->pressedSwitch(sw);
    }

}
