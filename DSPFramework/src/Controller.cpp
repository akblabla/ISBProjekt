///////////////////////////////////////////////////////////
//  Controller.cpp
//  Implementation of the Class Controller
//  Created on:      06-aug-2014 23:31:01
//  Original author: kbe
///////////////////////////////////////////////////////////

#include "Controller.h"
#include "SoundFilter3d.h"
#include "RegisterManager.h"
#include <math.h>

SoundFilter3D _filterFactory;   // create sound filter with orientation vector as parameter
SpatialSoundAlgo* _spatialAlgoLeft;
SpatialSoundAlgo* _spatialAlgoRight;
fract _filterLeft[FILTER_SIZE];
fract _filterRight[FILTER_SIZE];
float _pitch;
float _azim;
Controller::Controller(SpatialSoundAlgo* spatialAlgoLeft,SpatialSoundAlgo* spatialAlgoRight) //: m_band(0)
{
	_spatialAlgoLeft = spatialAlgoLeft;
	_spatialAlgoRight = spatialAlgoRight;
	_pitch = 0;
	_azim = 0;
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
			_azim -= 15;
			vector.x = sind(_azim)*cosd(_pitch);
			vector.y = cosd(_azim)*cosd(_pitch);
			vector.z = sind(_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
		}
		break;
		case KEY_SW5:
		{
			_azim += 15;
			vector.x = sind(_azim)*cosd(_pitch);
			vector.y = cosd(_azim)*cosd(_pitch);
			vector.z = sind(_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
		}
		break;
		case KEY_SW6:
			_pitch -= 15;
			vector.x = sind(_azim)*cosd(_pitch);
			vector.y = cosd(_azim)*cosd(_pitch);
			vector.z = sind(_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
			break;
		case KEY_SW7:
			_pitch += 15;
			vector.x = sind(_azim)*cosd(_pitch);
			vector.y = cosd(_azim)*cosd(_pitch);
			vector.z = sind(_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
			break;
	}
	_spatialAlgoLeft->modifyFilter(_filterLeft, FILTER_SIZE);
	_spatialAlgoRight->modifyFilter(_filterRight, FILTER_SIZE);
}


