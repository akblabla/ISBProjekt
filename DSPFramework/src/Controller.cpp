///////////////////////////////////////////////////////////
//  Controller.cpp
//  Implementation of the Class Controller
//  Created on:      06-aug-2014 23:31:01
//  Original author: kbe
///////////////////////////////////////////////////////////

#include "Controller.h"
#include "RegisterManager.h"
#include <math.h>
#include <cycle_count.h>
#include <cycles.h>
#include <stdio.h>

#include "SoundFilter3DFactory.h"
#define pi 3.141592
cycle_stats_t stats;

SoundFilter3DFactory _filterFactory;   // create sound filter with orientation vector as parameter
FirFilterAlgo* _spatialAlgoLeft;
FirFilterAlgo* _spatialAlgoRight;
fract _filterLeft[FILTER_SIZE];
fract _filterRight[FILTER_SIZE];
int _pitch;
int _azim;
fract tweedle_cos[] = {
#include "tweedle_cos.txt"
};
fract tweedle_sin[] = {
#include "tweedle_sin.txt"
};
#define TWEEDLE_LENGTH sizeof(tweedle_cos)/sizeof(fract)

Controller::Controller(FirFilterAlgo* spatialAlgoLeft,FirFilterAlgo* spatialAlgoRight) //: m_band(0)
{
	CYCLES_INIT(stats);
	_spatialAlgoLeft = spatialAlgoLeft;
	_spatialAlgoRight = spatialAlgoRight;
	_pitch = 0;
	_azim = 0;
}

Controller::~Controller()
{

}

void Controller::init(){
	fractVector3d vector = {
			1, 0, 0
	};
	_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
	_spatialAlgoLeft->modifyFilter(_filterLeft, FILTER_SIZE);
	_spatialAlgoRight->modifyFilter(_filterRight, FILTER_SIZE);
}

void Controller::updateUI()
{

}
fractVector3d calculateUnitVector(int azim, int pitch){
	fractVector3d vector;
	vector.x = tweedle_cos[_azim]*tweedle_cos[_pitch];
	vector.y = tweedle_sin[_azim]*tweedle_cos[_pitch];
	vector.z = tweedle_sin[_pitch];
	return vector;
}
void Controller::pressedSwitch(short sw)
{
	CYCLES_START(stats);
	fractVector3d vector;

	switch (sw) {
		case KEY_SW4:
		{
			_azim += TWEEDLE_LENGTH-1;
			_azim %=TWEEDLE_LENGTH;
			vector = calculateUnitVector(_azim,_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
		}
		break;
		case KEY_SW5:
		{
			_azim += 1;
			_azim %=TWEEDLE_LENGTH;
			vector = calculateUnitVector(_azim,_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
		}
		break;
		case KEY_SW6:
			_pitch += TWEEDLE_LENGTH-1;
			_pitch %=TWEEDLE_LENGTH;
			vector = calculateUnitVector(_azim,_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
			break;
		case KEY_SW7:
			_pitch += 1;
			_pitch %=TWEEDLE_LENGTH;
			vector = calculateUnitVector(_azim,_pitch);
			_filterFactory.makeFilters(_filterLeft, _filterRight, vector);
			break;
	}
	_spatialAlgoLeft->modifyFilter(_filterLeft, FILTER_SIZE);
	_spatialAlgoRight->modifyFilter(_filterRight, FILTER_SIZE);
	CYCLES_STOP(stats);
#if defined( DO_CYCLE_COUNTS )
	printf("make filter statistics:\n");
#endif
	CYCLES_PRINT(stats);
}


