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
fract* _firFilter;


Controller::Controller(fract* firFilter) //: m_band(0)
{
	_firFilter = firFilter;
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
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;

	switch (sw) {
		case KEY_SW4:
			vector.x = 0.5;
			vector.y = 0;
			vector.z = 0;
			filterFactory.makeFilter(_firFilter, vector);
			break;
		case KEY_SW5:
			vector.x = -0.5;
			vector.y = 0;
			vector.z = 0;
			filterFactory.makeFilter(_firFilter, vector);
			break;
		case KEY_SW6:
			vector.x = 0;
			vector.y = 0.5;
			vector.z = 0;
			filterFactory.makeFilter(_firFilter, vector);
			break;
		case KEY_SW7:
			vector.x = 0;
			vector.y = -0.5;
			vector.z = 0;
			filterFactory.makeFilter(_firFilter, vector);
			break;
	}
}


