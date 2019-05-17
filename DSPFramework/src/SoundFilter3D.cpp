/*
 * SoundFilter3D.cpp
 *
 *  Created on: 30. apr. 2019
 *      Author: kaspe
 */

#include "SoundFilter3D.h"

SoundFilter3D::SoundFilter3D() {

	_filterManager.init();
}

void SoundFilter3D::makeFilter(fract* filter, fractVector3d orientation){

	int triangleID;
	triangleID = findFilterTriangle(orientation);
	filterTriangle loadedTriangle = _filterManager.loadFilterTriangle(triangleID);
	fractVector3d weights;
	weights = findWeights(_filterManager.getTriangle(triangleID), orientation);

	const HRTFFilter* filterArray= _filterManager.getLoadedFilters();
	interpolateFilter(filter, loadedTriangle, weights);
/*	HRTFFilterHeader filterHeader;
	if (orientation.x == 0.5){
		filterHeader = _filterManager.loadFilter(0);
	}
	if (orientation.y == 0.5){
		filterHeader = _filterManager.loadFilter(10);
	}
	if (orientation.x == -0.5){
		filterHeader = _filterManager.loadFilter(20);
	}
	if (orientation.y == -0.5){
		filterHeader = _filterManager.loadFilter(30);
	}
	for (int i = filterHeader.delay; i<COEFFICIENTS+filterHeader.delay &&FILTER_SIZE;i++){
		filter[i] = filterHeader.filter->filter[i];
	}*/
}

//2. order taylor approximation of inverse squareroot around 1
accum SoundFilter3D::inverseSquareRoot2ndTaylor(accum x){
	return 1-(x-1)*((accum) 0.5)+(x-1)*(x-1)*((accum) 0.5*(accum) 1.5);
}
fract SoundFilter3D::SquareRootApprox(fract x){
	return (fract) sqrt((float) x);
}


fractVector3d SoundFilter3D::normalize(accumVector3d vector){
	accum squareLength = vector.x*vector.x+vector.y*vector.y+vector.z*vector.z;

	//2. order taylor approximation of inverse squareroot around 1
	accum inverseSquareLength = inverseSquareRoot2ndTaylor(squareLength);
	fractVector3d resultVector;
	resultVector.x = vector.x*inverseSquareLength;
	resultVector.y = vector.y*inverseSquareLength;
	resultVector.z = vector.z*inverseSquareLength;
	return resultVector;
}

void SoundFilter3D::interpolateFilter(fract* filterOut, filterTriangle triangle, fractVector3d weights ){
	int delay = 0;
	HRTFFilterHeader headers[3];
	for (int i = 0; i<2;++i){
		headers[i] = _filterManager.getHRTFHeader(triangle.filterIDs[0])
		delay+=headers[i].delay;
	}
	delay/=3;
	//Assume linear independence, so we need to square the weights to avoid changing the effect of the filter.
	weights.x = SquareRootApprox(weights.x);
	weights.y = SquareRootApprox(weights.y);
	weights.z = SquareRootApprox(weights.z);
	for (int i = 0; (i<FILTER_SIZE)&&(i<delay); i++){
		filterOut[i] = 0;
	}
	for (int i = 0; (i<COEFFICIENTS)&&(i+delay<FILTER_SIZE); i++){
		filterOut[i+delay] = headers[0].filter->coefficients[i]*weights.x
				+headers[1].filter->coefficients[i]*weights.y
				+headers[2].filter->coefficients[i]*weights.z;
	}
}
fractVector3d SoundFilter3D::findWeights(filterTriangle triangle, fractVector3d orientation){
	accumVector3d weightsNotNormalized;
	weightsNotNormalized.x = orientation.x*triangle.projectionMatrix[0][0]+orientation.y*triangle.projectionMatrix[1][0]+orientation.z*triangle.projectionMatrix[2][0];
	weightsNotNormalized.y = orientation.x*triangle.projectionMatrix[0][1]+orientation.y*triangle.projectionMatrix[1][1]+orientation.z*triangle.projectionMatrix[2][1];
	weightsNotNormalized.z = orientation.x*triangle.projectionMatrix[0][2]+orientation.y*triangle.projectionMatrix[1][2]+orientation.z*triangle.projectionMatrix[2][2];
	fractVector3d weights = normalize(weightsNotNormalized);
	return weights;
}
void SoundFilter3D::loadFilters(filterTriangle triangle){

}
int SoundFilter3D::findFilterTriangle(fractVector3d orientation){
	int triangleCount = 0;

	filterTriangle triangle;
	for (int i = 0; i<triangleCount; i++){
		triangle = _filterManager.getTriangle(i);
		accum dotProduct[3];
		for (int j = 0; j<3; ++i){
			fractVector3d edge = triangle.edges[j];
			dotProduct[j]=(accum)(edge.x*orientation.x)+(accum)(edge.y*orientation.y)+(accum)(edge.z*orientation.z);
		}
		if (dotProduct[0]>0 && dotProduct[1]>0 && dotProduct[2]>0){
			return i;
		}
	}
	return 0;
}

SoundFilter3D::~SoundFilter3D() {

}



