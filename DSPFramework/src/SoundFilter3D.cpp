/*
 * SoundFilter3D.cpp
 *
 *  Created on: 30. apr. 2019
 *      Author: kaspe
 */

#include "SoundFilter3D.h"

SoundFilter3D::SoundFilter3D() {


}

void SoundFilter3D::makeFilter(fract* filter, fractVector3d orientation){
	/*
	filterTriangle triangle;
	triangle = findFilterTriangle(orientation);
	loadFilter(*(triangle.filters[0]->filter));
	fractVector3d weights;
	weights = findWeights(triangle, orientation);
	interpolateFilter(filter, readyBuffer[0], readyBuffer[1], readyBuffer[2], weights);	*/
	HRTFFilterHeader filterHeader;
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
	for (int i = filterHeader.delay; i<FILTER_SIZE+filterHeader.delay;i++){
		filter[i] = filterHeader.filter[i];
	}

}

fractVector3d SoundFilter3D::normalize(accumVector3d vector){
	accum squareLength = vector.x*vector.x+vector.y*vector.y+vector.z*vector.z;

	//2. order taylor approximation of inverse squareroot around 1
	accum inverseSquareLength = 1-(squareLength-1)*((accum) 0.5)+(squareLength-1)*(squareLength-1)*((accum) 0.5*(accum) 1.5);
	fractVector3d resultVector;
	resultVector.x = vector.x*inverseSquareLength;
	resultVector.y = vector.y*inverseSquareLength;
	resultVector.z = vector.z*inverseSquareLength;
	return resultVector;
}

void SoundFilter3D::interpolateFilter(fract* filterOut, fract*a, fract*b, fract*c, fractVector3d weights){
	for (int i = 0; i<FIR_SIZE; i++){
		filterOut[i] = a[i]*weights.x+b[i]*weights.y+c[i]*weights.z;
	}
}
fractVector3d SoundFilter3D::findWeights(filterTriangle triangle, fractVector3d orientation){
	fractVector3d weights;
	weights.x = orientation.x*triangle.projectionMatrix[0][0]+orientation.y*triangle.projectionMatrix[1][0]+orientation.z*triangle.projectionMatrix[2][0];
	weights.y = orientation.x*triangle.projectionMatrix[0][1]+orientation.y*triangle.projectionMatrix[1][1]+orientation.z*triangle.projectionMatrix[2][1];
	weights.z = orientation.x*triangle.projectionMatrix[0][2]+orientation.y*triangle.projectionMatrix[1][2]+orientation.z*triangle.projectionMatrix[2][2];
	
	return weights;
}
void SoundFilter3D::loadFilters(filterTriangle triangle){

}
filterTriangle SoundFilter3D::findFilterTriangle(fractVector3d orientation){
	filterTriangle result;
	return result;
}

filterTriangle SoundFilter3D::getFilterTriangle(int ID){
	filterTriangle result;
	return result;
}
fractVector3d SoundFilter3D::getFilterOrientationVector(int filterIDs){
	fractVector3d result;
	return result;
}

SoundFilter3D::~SoundFilter3D() {

}



