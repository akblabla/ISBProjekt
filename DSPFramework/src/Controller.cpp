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
#define pi 3.141592
SoundFilter3D _filterFactory;   // create sound filter with orientation vector as parameter
FirFilterAlgo* _spatialAlgoLeft;
FirFilterAlgo* _spatialAlgoRight;
fract _filterLeft[FILTER_SIZE];
fract _filterRight[FILTER_SIZE];
int _pitch;
int _azim;
fract tweedle[] = {
		0.9962,
		    0.9397,
		    0.8192,
		    0.6428,
		    0.4226,
		    0.1736,
		   -0.0872,
		   -0.3420,
		   -0.5736,
		   -0.7660,
		   -0.9063,
		   -0.9848,
		   -0.9962,
		   -0.9397,
		   -0.8192,
		   -0.6428,
		   -0.4226,
		   -0.1736,
		    0.0872,
		    0.3420,
		    0.5736,
		    0.7660,
		    0.9063,
		    0.9848,
		    0.9962};

Controller::Controller(FirFilterAlgo* spatialAlgoLeft,FirFilterAlgo* spatialAlgoRight) //: m_band(0)
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
fractVector3d calculateUnitVector(int azim, int pitch){
	fractVector3d vector;
	vector.x = tweedle[_azim]*tweedle[_pitch];
	vector.y = tweedle[(_azim+18)%24]*tweedle[_pitch];
	vector.z = tweedle[(_pitch+18)%24];
	return vector;
}
void Controller::pressedSwitch(short sw)
{
	fractVector3d vector;

	switch (sw) {
		case KEY_SW4:
		{
			_azim += 23;
			_azim %=24;
			vector = calculateUnitVector(_azim,_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
		}
		break;
		case KEY_SW5:
		{
			_azim += 1;
			_azim %=24;
			vector = calculateUnitVector(_azim,_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
		}
		break;
		case KEY_SW6:
			_pitch += 23;
			_pitch %=24;
			vector = calculateUnitVector(_azim,_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
			break;
		case KEY_SW7:
			_pitch += 1;
			_pitch %=24;
			vector = calculateUnitVector(_azim,_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
			break;
	}
	fract* impulse_ptr_left = _filterLeft;
	fract* impulse_ptr_right = _filterRight;
	_spatialAlgoLeft->modifyFilter(_filterLeft, FILTER_SIZE);
	_spatialAlgoRight->modifyFilter(_filterRight, FILTER_SIZE);
}


