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
class SoundFilter3D {
public:
	SoundFilter3D();
	virtual ~SoundFilter3D();
	void makeFilter(fract* filter, fractVector3d orientation);

private:
	
	fractVector3d normalize(accumVector3d vector);
	void interpolateFilter(fract* filterOut, fract*a, fract*b, fract*c, fractVector3d weights);
	fractVector3d findWeights(filterTriangle triangle, fractVector3d orientation);
	void loadFilters(filterTriangle triangle);
	filterTriangle findFilterTriangle(fractVector3d orientation);
	
	filterTriangle getFilterTriangle(int ID);
	fractVector3d getFilterOrientationVector(int filterIDs);
	
	HRTFFilterHeader _filterBuffers[3][2];
	filterTriangle _filterTriangles[2];
	filterTriangle* _readyTriangle;
	HRTFFilterHeader* _readyBuffer[3];
	filterTriangle* _loadingTriangle;
	HRTFFilterHeader* _loadingBuffer[3];
	FilterManager _filterManager;
};

#endif /* SOUNDFILTER3D_H_ */
