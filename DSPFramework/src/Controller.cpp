///////////////////////////////////////////////////////////
//  Controller.cpp
//  Implementation of the Class Controller
//  Created on:      06-aug-2014 23:31:01
//  Original author: kbe
///////////////////////////////////////////////////////////

#include "Controller.h"
#include "SoundFilter3d.h"
#include "RegisterManager.h"

SoundFilter3D filterFactory;   // create sound filter with orientation vector as parameter
fract firFilter[FIR_SIZE];


Controller::Controller() //: m_band(0)
{

}

Controller::~Controller()
{

}

void Controller::updateUI()
{

}

void Controller::pressedSwitch(short sw)
{
	fractVector3d vector;
	switch (sw) {
		case KEY_SW4:
			vector.x++;
			filterFactory.makeFilter(firFilter, vector);
			break;
		case KEY_SW5:
			vector.x--;
			filterFactory.makeFilter(firFilter, vector);
			break;
		case KEY_SW6:
			vector.y++;
			filterFactory.makeFilter(firFilter, vector);
			break;
		case KEY_SW7:
			vector.y--;
			filterFactory.makeFilter(firFilter, vector);
			break;
	}
}


