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
	int filterIDs[3];
	filterSearch(filterIDs, orientation);
	loadFilter(filterIDs);
	fractVector3d weights;
	weights = findWeights(filterIDs, orientation);
	interpolateFilter(filter, readyBuffer[0], readyBuffer[1], readyBuffer[2], weights);	
}

fractVector3d SoundFilter3D::normalize(accumVector3d vector){
	accum squareLength = vector.x*vector.x+vector.y*vector.y+vector.z*vector.z;
	accum inverseSquareLength = 1-(squareLength-1)*(0.5)+(squareLength-1)*(squareLength-1)*(0.5*1.5); //2. order taylor approximation of inverse squareroot around 1
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
fractVector3d SoundFilter3D::findWeights(int* filterIDs, fractVector3d orientation){
	accumMatrix3_3 projectionMatrix = getProjectionMatrix(filterIDs);
	fractVector3d weights;
	weights.x = orientation.x*projectionMatrix.value[1][1]+orientation.y*projectionMatrix.value[2][1]+orientation.z*projectionMatrix.value[3][1];
	weights.y = orientation.x*projectionMatrix.value[1][2]+orientation.y*projectionMatrix.value[2][2]+orientation.z*projectionMatrix.value[3][2];
	weights.z = orientation.x*projectionMatrix.value[1][3]+orientation.y*projectionMatrix.value[2][3]+orientation.z*projectionMatrix.value[3][3];
	
	return weights;
}
void SoundFilter3D::loadFilter(int* filterIDs){
}
accumMatrix3_3 SoundFilter3D::getProjectionMatrix(int* filterIDs){
}
fractVector3d SoundFilter3D::getFilterOrientationVector(int filterIDs){
}

void SoundFilter3D::filterSearch(int* filterIDs, fractVector3d orientation){
}

SoundFilter3D::~SoundFilter3D() {

}



