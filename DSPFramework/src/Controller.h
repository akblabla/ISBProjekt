///////////////////////////////////////////////////////////
//  Controller.h
//  Implementation of the Class Controller
//  Created on:      06-aug-2014 23:31:01
//  Original author: kbe
///////////////////////////////////////////////////////////

#if !defined(CONTROLLER__INCLUDED_)
#define CONTROLLER__INCLUDED_
#include <stdfix.h>
#include "SpatialSoundAlgo.h"
#include "FilterStructs.h"

class Controller
{

public:

	Controller::Controller(SpatialSoundAlgo* spatialAlgoLeft, SpatialSoundAlgo* spatialAlgoRight);
	virtual ~Controller();
	void pressedSwitch(short sw);

protected:
    void updateUI();
	//short m_band;
    fractVector3d _orientation;
};

#endif // !defined(CONTROLLER__INCLUDED_)
