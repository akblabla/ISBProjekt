/*
 * SoundFilter3D.cpp
 *
 *  Created on: 30. apr. 2019
 *      Author: kaspe
 */

#include "SoundFilter3DFactory.h"

SoundFilter3DFactory::SoundFilter3DFactory() {

	_filterManager.init();
}

void SoundFilter3DFactory::makeFilters(fract* filterLeft, fract* filterRight, fractVector3d orientation){

	fractVector3d mirrorOrientation = orientation;
	mirrorOrientation.y *= -1;
	makeFilter(filterLeft,orientation);
	makeFilter(filterRight,mirrorOrientation);
}

void SoundFilter3DFactory::makeFilter(fract* filter, fractVector3d orientation){

	int triangleID;
	triangleID = findFilterTriangle(orientation);
	filterTriangle triangle = _filterManager.getTriangle(triangleID);
	fractVector3d weights;
	weights = findWeights(triangle, orientation);
	interpolateFilter(filter, triangle, weights);
}


//2. order taylor approximation of inverse squareroot around 1
accum SoundFilter3DFactory::inverseSquareRoot2ndTaylor(accum x){
	return 1-(x-1)*((accum) 0.5)+(x-1)*(x-1)*((accum) 0.5*(accum) 1.5)*0.5;
}
fract SoundFilter3DFactory::SquareRootApprox(fract x){
	return (fract) sqrt((float) x);
}


fractVector3d SoundFilter3DFactory::normalize(accumVector3d vector){
	accum squareLength = vector.x*vector.x+vector.y*vector.y+vector.z*vector.z;

	//2. order taylor approximation of inverse squareroot around 1
	accum inverseSquareLength = inverseSquareRoot2ndTaylor(squareLength);
	fractVector3d resultVector;
	resultVector.x = vector.x*inverseSquareLength;
	resultVector.y = vector.y*inverseSquareLength;
	resultVector.z = vector.z*inverseSquareLength;
	return resultVector;
}

void SoundFilter3DFactory::interpolateFilter(fract* filterOut, filterTriangle triangle, fractVector3d weights ){
	int delay = 0;
	HRTFFilterHeader headers[3];
	HRTFFilter inputFilters[3];
	for (int i = 0; i<3;++i){
		int id = triangle.filterIDs[i];
		headers[i] = _filterManager.getHRTFHeader(id);
		inputFilters[i] = _filterManager.getHRTFFilter(id);
		delay+=headers[i].delay;
	}
	delay/=3;
	//Assume linear independence, so we need to square the weights to avoid changing the effect of the filter.
	weights.x = SquareRootApprox(weights.x);
	weights.y = SquareRootApprox(weights.y);
	weights.z = SquareRootApprox(weights.z);
	for (int i = 0; (i<FILTER_SIZE); i++){
		filterOut[i] = 0;
	}
	for (int i = 0; (i<COEFFICIENTS)&&(i+delay<FILTER_SIZE); i++){
		filterOut[i+delay] = inputFilters[0].coefficients[i]*weights.x
				+inputFilters[1].coefficients[i]*weights.y
				+inputFilters[2].coefficients[i]*weights.z;
	}
}
fractVector3d SoundFilter3DFactory::findWeights(filterTriangle triangle, fractVector3d orientation){
	accumVector3d weightsNotNormalized;
	weightsNotNormalized.x = orientation.x*triangle.projectionMatrix[0][0]+orientation.y*triangle.projectionMatrix[1][0]+orientation.z*triangle.projectionMatrix[2][0];
	weightsNotNormalized.y = orientation.x*triangle.projectionMatrix[0][1]+orientation.y*triangle.projectionMatrix[1][1]+orientation.z*triangle.projectionMatrix[2][1];
	weightsNotNormalized.z = orientation.x*triangle.projectionMatrix[0][2]+orientation.y*triangle.projectionMatrix[1][2]+orientation.z*triangle.projectionMatrix[2][2];

	//if a weight is negative, it means our orientation is outside the found triangle, so orientate the sound so it is at the closest spot on the triangle.
	if (weightsNotNormalized.x<0)
		weightsNotNormalized.x = 0;
	if (weightsNotNormalized.y<0)
		weightsNotNormalized.y = 0;
	if (weightsNotNormalized.z<0)
		weightsNotNormalized.z = 0;
	fractVector3d weights = normalize(weightsNotNormalized);
	return weights;
}

int SoundFilter3DFactory::findFilterTriangle(fractVector3d orientation){
	filterTriangle triangle;
	for (int i = 0; i<TRIANGLES; i++){
		triangle = _filterManager.getTriangle(i);
		accum dotProduct[3];
		for (int j = 0; j<3; ++j){
			longFractVector3d edge = triangle.edges[j];
			dotProduct[j]=(accum)(edge.x*orientation.x)+(accum)(edge.y*orientation.y)+(accum)(edge.z*orientation.z);
		}
		if (dotProduct[0]>=-0.000030517578125 && dotProduct[1]>=-0.000030517578125 && dotProduct[2]>=-0.000030517578125){
			return i;
		}
	}
	return 0;
}

SoundFilter3DFactory::~SoundFilter3DFactory() {

}



