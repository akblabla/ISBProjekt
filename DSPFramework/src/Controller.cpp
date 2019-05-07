///////////////////////////////////////////////////////////
//  Controller.cpp
//  Implementation of the Class Controller
//  Created on:      06-aug-2014 23:31:01
//  Original author: kbe
///////////////////////////////////////////////////////////

#include "Controller.h"

Controller::Controller() : m_band(0)
{

}


Controller::~Controller()
{

}

void Controller::updateUI()
{
	//SetMaskLed(0x0f, m_band<<4);
}


void Controller::pressedSwitch(short sw)
{
	/*switch (sw) {
		case KEY_SW4:
			break;
		case KEY_SW5:
			break;
		case KEY_SW6:
			break;
		case KEY_SW7:
			break;
	}*/
}


