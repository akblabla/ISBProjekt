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
#include "FilterDMA.h"

class FilterManager {
public:
	FilterManager();
	void init();
	/*starts loading the filter with the given id and returns the previous loaded filter.
	 Make sure that an appropiate amount of time has passed since last loadFilter call, otherwise the returned pointer won't point to valid data.*/
	HRTFFilterHeader loadFilter(int id);
	/*starts loading the filter triangles with the given ids and returns the previous loaded filter triangles.
	 *Make sure that an appropiate amount of time has passed since last loadFilterTriangles call.
	*/
	void loadFilterTriangles(HRTFFilter* filtersA, int* triangleIDA, HRTFFilter* filtersB, int* triangleIDB);
	//returns the loaded filter. Make sure that an appropiate amount of time has passed since last loadFilter call.
	const HRTFFilter* getLoadedFilters();
	//returns the loaded filter triangle. Make sure that an appropiate amount of time has passed since last loadFilterTriangle call.
	filterTriangle getLoadedFilterTriangle();
	filterTriangle getTriangle(int id);
	HRTFFilterHeader getHRTFHeader(int id);
private:
	short readFile(short buffer[], short bufSize, char *fileName);
	short readFracts(fract buffer[], short bufSize, char *fileName);


};

#endif /* FILTERMANAGER_H_ */
