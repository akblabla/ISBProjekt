/*
 * FilterManager.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Andreas
 */

#include <stdio.h>
#include "FilterManager.h"


section("sdram0_bank0") HRTFFilter HRTFFilterArray[FILTERS] = {
#include "impulse_responses.txt"
};
HRTFFilterHeader HRTFFilterHeaderArray[FILTERS] =
{
#include "filter_headers.txt"
};
filterTriangle filterTriangleArray[TRIANGLES] =
{
#include "filter_triangle.txt"
};

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

}

HRTFFilter FilterManager::getHRTFFilter(int id)
{
	return HRTFFilterArray[id];
}
filterTriangle FilterManager::getTriangle(int id)
{
	return filterTriangleArray[id];
}

HRTFFilterHeader FilterManager::getHRTFHeader(int id)
{
	return HRTFFilterHeaderArray[id];
}
