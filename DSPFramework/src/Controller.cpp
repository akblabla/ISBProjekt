///////////////////////////////////////////////////////////
//  Controller.cpp
//  Implementation of the Class Controller
//  Created on:      06-aug-2014 23:31:01
//  Original author: kbe
///////////////////////////////////////////////////////////

#include "Controller.h"
#include "SoundFilter3d.h"
#include "RegisterManager.h"

SoundFilter3D _filterFactory;   // create sound filter with orientation vector as parameter
SpatialSoundAlgo* _spatialAlgo;
fract _filter[FILTER_SIZE];

Controller::Controller(SpatialSoundAlgo* spatialAlgo) //: m_band(0)
{
	_spatialAlgo = spatialAlgo;
	_orientation.x = 1;
	_orientation.y = 0;
	_orientation.z = 0;
}

Controller::~Controller()
{

}

void Controller::updateUI()
{

}

#define cos15 0.9659258262k
#define sin15 0.2588190451k

void Controller::pressedSwitch(short sw)
{
	fractVector3d vector;

	switch (sw) {
		case KEY_SW4:
		{
			accumVector3d result = _orientation;
			result.x = _orientation.x*cos15 - _orientation.y*sin15;
			result.y = _orientation.x*sin15 + _orientation.y*cos15;
			_orientation = result;
			vector.x = 0.5;
			vector.y = 0;
			vector.z = 0;
			_filterFactory.makeFilter(_filter, vector);
			_spatialAlgo->create(_filter, FILTER_SIZE);
		}
		break;
		case KEY_SW5:
		{
			accumVector3d result = _orientation;
			result.x = _orientation.x*cos15 + _orientation.y*sin15;
			result.y = -_orientation.x*sin15 + _orientation.y*cos15;
			_orientation = result;
			vector.x = -0.5;
			vector.y = 0;
			vector.z = 0;
			_filterFactory.makeFilter(_filter, vector);
			_spatialAlgo->create(_filter, FILTER_SIZE);
		}
		break;
		case KEY_SW6:
			vector.x = 0;
			vector.y = 0.5;
			vector.z = 0;
			_filterFactory.makeFilter(_filter, vector);
			_spatialAlgo->create(_filter, FILTER_SIZE);
			break;
		case KEY_SW7:
			vector.x = 0;
			vector.y = -0.5;
			vector.z = 0;
			_filterFactory.makeFilter(_filter, vector);
			_spatialAlgo->create(_filter, FILTER_SIZE);
			break;
	}
}


