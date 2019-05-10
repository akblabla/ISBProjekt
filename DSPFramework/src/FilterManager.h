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
	void loadFilter(HRTFFilterHeader* destination,int id);
	void loadFilterTriangle(filterTriangle * triangle, HRTFFilterHeader* filters,int id);
private:
	short readFile(short buffer[], short bufSize, char *fileName);
};

#endif /* FILTERMANAGER_H_ */
