/*
 * FilterManager.h
 *
 *  Created on: May 10, 2019
 *      Author: Andreas
 */

#ifndef FILTERMANAGER_H_
#define FILTERMANAGER_H_
#include "Algorithm.h"
#include "FilterStructs.h"

class FilterManager {
public:
	FilterManager();
	void init();
	/*starts loading the filter with the given id and returns the previous loaded filter.
	 Make sure that an appropiate amount of time has passed since last loadFilter call, otherwise the returned pointer won't point to valid data.*/
	HRTFFilterHeader loadFilter(int id);
	/*starts loading the filter triangle with the given id and returns the previous loaded filter triangle.
	 *Make sure that an appropiate amount of time has passed since last loadFilterTriangle call.
	*/
	filterTriangle loadFilterTriangle(int id);
	//returns the loaded filter. Make sure that an appropiate amount of time has passed since last loadFilter call.
	HRTFFilterHeader getLoadedFilter();
	//returns the loaded filter triangle. Make sure that an appropiate amount of time has passed since last loadFilterTriangle call.
	filterTriangle getLoadedFilterTriangle();
private:
	short readFile(short buffer[], short bufSize, char *fileName);

	HRTFFilter filterBuffers[3][2];
	filterTriangle loadingTriangle;
	HRTFFilterHeader loadingFilter[3];

};

#endif /* FILTERMANAGER_H_ */
