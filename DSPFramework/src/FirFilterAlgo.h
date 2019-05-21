/*
 * SpatialSoundAlgo.h
 *
 *  Created on: 23. apr. 2019
 *      Author: kaspe
 */

#ifndef FIRFILTERALGO_H_
#define FIRFILTERALGO_H_

#include "Algorithm.h"
#include <stdfix.h>
#include <filter.h>
#include "FilterStructs.h"

class FirFilterAlgo : public Algorithm {
public:
	FirFilterAlgo();
	virtual ~FirFilterAlgo();

	virtual void process(short* input, short* output, short len);
	virtual void create();
	virtual void create(fract* filter, int length);
	virtual void modifyFilter(fract* filter, int length);

	int _cir_ptr;
	fract* _filterPtr;
	#pragma section("L1_data_a")
	fract _firFilter[FILTER_SIZE];
	#pragma section("L1_data_b")
	fract _delayLine[FILTER_SIZE];

	fir_state_fx16 _filterState;

	fract _firFilterTemp[FILTER_SIZE];
	fir_state_fx16 _filterStateTemp;
	bool _changedFilter;

};
#endif /* FIRFILTERALGO_H_ */
