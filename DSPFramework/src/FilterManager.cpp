/*
 * FilterManager.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Andreas
 */

#include <stdio.h>
#include "FilterManager.h"

#define FILTERS 187
#define COEFFICIENTS 150
#define TRIANGLES 100

section("sdram0_bank0") HRTFFilter HRTFFilterArray[FILTERS];
HRTFFilterHeader HRTFFilterHeaderArray[FILTERS];
filterTriangle filterTriangleArray[TRIANGLES];

section("sdram0_bank0") short coefficientBuffer[FILTERS*COEFFICIENTS];
section("sdram0_bank0") short delays[FILTERS];
section("sdram0_bank0") short directionVectors[3*FILTERS];


FilterManager::FilterManager()
{
}
	void FilterManager::init()
	{


		// read filter coefficients, delays and direction vectors
		short error = readFile(coefficientBuffer,FILTERS*COEFFICIENTS,"..\\src\\impulse_responses.txt");
		error = readFile(delays,FILTERS,"..\\src\\delay.txt");
		error = readFile(directionVectors,3*FILTERS,"..\\src\\direction_vectors.txt");

		// sort data
		for(short n = 0;n < FILTERS;n++)
		{
			for(short i = 0;i < COEFFICIENTS;i++)
			{
				HRTFFilterArray[n].filter[i] = coefficientBuffer[n*COEFFICIENTS + i];

			}
			HRTFFilterHeaderArray[n].delay = delays[n];
			HRTFFilterHeaderArray[n].filter = &(HRTFFilterArray[n]);
			HRTFFilterHeaderArray[n].orientation.x = directionVectors[n*3];
			HRTFFilterHeaderArray[n].orientation.y = directionVectors[n*3+1];
			HRTFFilterHeaderArray[n].orientation.z = directionVectors[n*3+2];
		}

	}

	HRTFFilterHeader FilterManager::loadFilter(int id)
	{
		return HRTFFilterHeaderArray[id];
	}

	filterTriangle loadFilterTriangle(int id)
	{
		struct filterTriangle triangle;
		return triangle;
	}

	filterTriangle FilterManager::loadFilterTriangle(int id)
	{
		struct filterTriangle triangle;
		return triangle;
	}

	filterTriangle getLoadedFilterTriangle()
	{
		struct filterTriangle triangle;
		return triangle;
	}

	short FilterManager::readFile(short buffer[], short bufSize, char *fileName)
	{
		return 0;
	}
