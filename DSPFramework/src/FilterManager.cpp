/*
 * FilterManager.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Andreas
 */

#include <stdio.h>
#include "FilterManager.h"

FilterManager::FilterManager()
{
}
	void FilterManager::init()
	{
	}

	HRTFFilterHeader FilterManager::loadFilter(int id)
	{
		struct HRTFFilterHeader filterHeader;
		return filterHeader;
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
