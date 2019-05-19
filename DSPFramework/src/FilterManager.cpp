/*
 * FilterManager.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Andreas
 */

#include <stdio.h>
#include "FilterManager.h"

section("sdram0_bank0") fract coefficientBuffer[COEFFICIENTS*FILTERS] =
{
#include "impulse_responses.txt"
};
short delays[FILTERS] =
{
#include "delay.txt"
};
accum directionVectors[3*FILTERS] =
{
#include "direction_vectors.txt"
};
accum triangleData[21*TRIANGLES] =
{
#include "filterTriangle.txt"
};

section("sdram0_bank0") HRTFFilter HRTFFilterArray[FILTERS];
HRTFFilterHeader HRTFFilterHeaderArray[FILTERS];
filterTriangle filterTriangleArray[TRIANGLES];

HRTFFilter filterBuffers[3][2][2];
int loadingTriangleID[2][2];
int currentBuffer;
DMADestriptor srcDMADescriptors[5];
DMADestriptor destDMADescriptors[5];



FilterManager::FilterManager()
{
}
void FilterManager::init()
{


	// read filter coefficients, delays and direction vectors
	//short error = readFracts(coefficientBuffer,FILTERS*COEFFICIENTS,"..\\src\\impulse_responses.txt");
	//error = readFile(delays,FILTERS,"..\\src\\delay.txt");
	//error = readFracts(directionVectors,3*FILTERS,"..\\src\\direction_vectors.txt");

	// sort data
	for(int n = 0;n < FILTERS;n++)
	{
		for(int i = 0;i < COEFFICIENTS;i++)
		{
			HRTFFilterArray[n].coefficients[i] = coefficientBuffer[n*COEFFICIENTS + i];
		}
		// initialize HRTFFilterHeaderArray
		HRTFFilterHeaderArray[n].delay = delays[n];
		HRTFFilterHeaderArray[n].filter = &(HRTFFilterArray[n]);
		HRTFFilterHeaderArray[n].orientation.x = directionVectors[n*3];
		HRTFFilterHeaderArray[n].orientation.y = directionVectors[n*3+1];
		HRTFFilterHeaderArray[n].orientation.z = directionVectors[n*3+2];


	}

	// initialize filterTriangleArray
	for(short n = 0;n < TRIANGLES;n++)
	{
		for(short i = 0; i < 3; i++ )
		{
			filterTriangleArray[n].filterIDs[i] = triangleData[n*21 + i];
			filterTriangleArray[n].edges[i].x = triangleData[n*21 + 3*(i+1)];
			filterTriangleArray[n].edges[i].y = triangleData[n*21 + 3*(i+1) + 1];
			filterTriangleArray[n].edges[i].z = triangleData[n*21 + 3*(i+1) + 2];
			for(short m = 0;m < 3; m++ )
			{
				filterTriangleArray[n].projectionMatrix[i][m] = triangleData[n*21 + 12 + m + 3*i];
			}

		}
	}

}

HRTFFilterHeader FilterManager::loadFilter(int id)
{
	return HRTFFilterHeaderArray[id];
}
filterTriangle FilterManager::getTriangle(int id)
{
	return filterTriangleArray[id];
}


void FilterManager::loadFilterTriangles(HRTFFilter* filtersA, int* triangleIDA, HRTFFilter* filtersB, int* triangleIDB)
{
	/*filterTriangle triangleA = getTriangle(*triangleIDA);
	filterTriangle triangleB = getTriangle(*triangleIDB);

	loadingTriangleID[0][currentBuffer] = *triangleIDA;
	loadingTriangleID[1][currentBuffer] = *triangleIDB;

	srcDMADescriptors[0] = makeDMADescriptor(&(HRTFFilterArray[triangleA.filterIDs[1]]), &(srcDMADescriptors[1]), 0, 0);
	srcDMADescriptors[1] = makeDMADescriptor(&(HRTFFilterArray[triangleA.filterIDs[2]]), &(srcDMADescriptors[2]), 0, 0);
	srcDMADescriptors[2] = makeDMADescriptor(&(HRTFFilterArray[triangleB.filterIDs[0]]), &(srcDMADescriptors[3]), 0, 0);
	srcDMADescriptors[3] = makeDMADescriptor(&(HRTFFilterArray[triangleB.filterIDs[1]]), &(srcDMADescriptors[4]), 0, 0);
	srcDMADescriptors[4] = makeDMADescriptor(&(HRTFFilterArray[triangleB.filterIDs[2]]), 0, 0, 1);

	destDMADescriptors[0] = makeDMADescriptor(&(filterBuffers[1][0][currentBuffer]), &(destDMADescriptors[1]), 1, 0);
	destDMADescriptors[1] = makeDMADescriptor(&(filterBuffers[2][0][currentBuffer]), &(destDMADescriptors[2]), 1, 0);
	destDMADescriptors[2] = makeDMADescriptor(&(filterBuffers[0][1][currentBuffer]), &(destDMADescriptors[3]), 1, 0);
	destDMADescriptors[3] = makeDMADescriptor(&(filterBuffers[1][1][currentBuffer]), &(destDMADescriptors[4]), 1, 0);
	destDMADescriptors[4] = makeDMADescriptor(&(filterBuffers[2][1][currentBuffer]), 0, 1, 1);

	startFilterDMA(&(HRTFFilterArray[triangleA.filterIDs[0]]), &(filterBuffers[0][0][currentBuffer]), &(srcDMADescriptors[0]), &(destDMADescriptors[0]));

	currentBuffer++;
	if (currentBuffer>1) currentBuffer = 0;
	*triangleIDA = loadingTriangleID[0][currentBuffer];
	*triangleIDA = loadingTriangleID[1][currentBuffer];
	filtersA = &(filterBuffers[0][0][currentBuffer]);
	filtersB = &(filterBuffers[0][0][currentBuffer]);*/
	for (int i = 0; i<3;++i){
		for (int j = 0; j<COEFFICIENTS;++j){
			int filterIDA = getTriangle(*triangleIDA).filterIDs[i];
			int filterIDB = getTriangle(*triangleIDB).filterIDs[i];
			filtersA[i].coefficients[j]=HRTFFilterArray[filterIDA].coefficients[j];
			filtersB[i].coefficients[j]=HRTFFilterArray[filterIDB].coefficients[j];
		}
	}
}

const HRTFFilter* FilterManager::getLoadedFilters()
{
	return HRTFFilterArray;
}

filterTriangle FilterManager::getLoadedFilterTriangle()
{
	filterTriangle triangle;
	return triangle;
}

HRTFFilterHeader FilterManager::getHRTFHeader(int id)
{
	return HRTFFilterHeaderArray[id];
}

short FilterManager::readFile(short buffer[], short bufSize, char *fileName)
{
	short error = -1;
	FILE *fp;
	short tmp;

	fp=fopen(fileName , "r");
	if (fp)
	{
		for(short n=0; n < bufSize; n++) {
			fscanf(fp, "%hd,\n", &tmp);
			buffer[n] = tmp;
		}
		fclose(fp);
		error = 0;
	}
	return error;
}

short FilterManager::readFracts(fract buffer[], short bufSize, char *fileName)
{
	short error = -1;
	FILE *fp;
	float tmp;

	fp=fopen(fileName , "r");
	if (fp)
	{
		for(short n=0; n < bufSize; n++) {
			fscanf(fp, "%f,\n", &tmp);
			buffer[n] = tmp;
		}
		fclose(fp);
		error = 0;
	}
	return error;
}
