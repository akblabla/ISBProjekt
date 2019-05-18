/*
 * SpatialSoundAlgo.h
 *
 *  Created on: 23. apr. 2019
 *      Author: kaspe
 */

#ifndef SPATIALSOUNDALGO_H_
#define SPATIALSOUNDALGO_H_

#include "Algorithm.h"
#include <stdfix.h>
#include <filter.h>
#include "FilterStructs.h"

class SpatialSoundAlgo : public Algorithm {
public:
	SpatialSoundAlgo();
	virtual ~SpatialSoundAlgo();

	virtual void process(short* input, short* output, short len);
	virtual void create();
	virtual void create(fract* filter, int length);
	virtual void modifyFilter(fract* filter, int length);

	float fastInverseSquare(float input);
	fract _firFilter[FILTER_SIZE];
	fract _delayLine[FILTER_SIZE];
	fir_state_fx16 _filterState;

	fract _firFilterTemp[FILTER_SIZE];
	fir_state_fx16 _filterStateTemp;
	bool _changedFilter;

};

#endif /* SPATIALSOUNDALGO_H_ */
