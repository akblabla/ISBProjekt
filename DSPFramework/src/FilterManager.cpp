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

section("sdram0_bank0") HRTFFilter HRTFFilterArray[FILTERS];
HRTFFilterHeader HRTFFilterHeaderArray[FILTERS];
filterTriangle filterTriangleArray[TRIANGLES];




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
		for(short n = 0;n < FILTERS;n++)
		{
			for(short i = 0;i < COEFFICIENTS;i++)
			{
				HRTFFilterArray[n].filter[i] = coefficientBuffer[n*COEFFICIENTS + i];

			}
			// initialize HRTFFilterHeaderArray
			HRTFFilterHeaderArray[n].delay = delays[n];
			HRTFFilterHeaderArray[n].filter = &(HRTFFilterArray[n]);
			HRTFFilterHeaderArray[n].orientation.x = directionVectors[n*3];
			HRTFFilterHeaderArray[n].orientation.y = directionVectors[n*3+1];
			HRTFFilterHeaderArray[n].orientation.z = directionVectors[n*3+2];
			// initialize filterTriangleArray.filters

		}


	}

	HRTFFilterHeader FilterManager::loadFilter(int id)
	{
		return HRTFFilterHeaderArray[id];
	}


	filterTriangle FilterManager::loadFilterTriangle(int id)
	{
		filterTriangle triangle;
		return triangle;
	}

	HRTFFilterHeader FilterManager::getLoadedFilter()
	{
		return HRTFFilterHeaderArray[0];
	}

	filterTriangle FilterManager::getLoadedFilterTriangle()
	{
		filterTriangle triangle;
		return triangle;
	}

	filterTriangle FilterManager::getTriangle(int id)
	{
		return filterTriangleArray[id];
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
