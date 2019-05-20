/*
 * SoundFilter3D.h
 *
 *  Created on: 30. apr. 2019
 *      Author: kaspe
 */

#ifndef SOUNDFILTER3DFACTORY_H_
#define SOUNDFILTER3DFACTORY_H_
#include <stdfix.h>
#include "FilterStructs.h"
#include "FilterManager.h"
#include <math.h>
class SoundFilter3DFactory {
public:
	SoundFilter3DFactory();
	virtual ~SoundFilter3DFactory();
	void makeFilters(fract* leftFilter, fract* rightFilter, fractVector3d orientation);

private:
	void makeFilter(fract* filter, fractVector3d orientation);
	fractVector3d normalize(accumVector3d vector);
	accum inverseSquareRoot2ndTaylor(accum x);
	fract SquareRootApprox(fract x);
	void interpolateFilter(fract* filterOut, filterTriangle triangle, fractVector3d weights);
	fractVector3d findWeights(filterTriangle triangle, fractVector3d orientation);
	int findFilterTriangle(fractVector3d orientation);

	FilterManager _filterManager;
};

#endif /* SOUNDFILTER3DFACTORY_H_ */
