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
	HRTFFilter getHRTFFilter(int id);
	filterTriangle getTriangle(int id);
	HRTFFilterHeader getHRTFHeader(int id);

};

#endif /* FILTERMANAGER_H_ */
