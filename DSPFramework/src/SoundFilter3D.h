/*
 * SoundFilter3D.h
 *
 *  Created on: 30. apr. 2019
 *      Author: kaspe
 */

#ifndef SOUNDFILTER3D_H_
#define SOUNDFILTER3D_H_
#include <stdfix.h>
#include "FilterStructs.h"
#include "FilterManager.h"
#include <math.h>
class SoundFilter3D {
public:
	SoundFilter3D();
	virtual ~SoundFilter3D();
	void makeFilters(fract* leftFilter, fract* rightFilter, fractVector3d orientation);

private:
	
	fractVector3d normalize(accumVector3d vector);
	accum inverseSquareRoot2ndTaylor(accum x);
	fract SquareRootApprox(fract x);

	void interpolateFilter(fract* filterOut, filterTriangle triangle, HRTFFilter* inputFilters, fractVector3d weights);
	fractVector3d findWeights(filterTriangle triangle, fractVector3d orientation);
	void loadFilters(filterTriangle triangle);
	int findFilterTriangle(fractVector3d orientation);

	FilterManager _filterManager;
};

#endif /* SOUNDFILTER3D_H_ */
