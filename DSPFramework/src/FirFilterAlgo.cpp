/*
 * SpatialSoundAlgo.cpp
 *
 *  Created on: 23. apr. 2019
 *      Author: kaspe
 */

#include "FirFilterAlgo.h"
#include <builtins.h>


FirFilterAlgo::FirFilterAlgo() {
	fir_init(_filterState,_firFilter,_delayLine,FILTER_SIZE,0);
	_filterPtr = _firFilter;
}
float y = 0;
FirFilterAlgo::~FirFilterAlgo() {
	// TODO Auto-generated destructor stub
}

void FirFilterAlgo::process(short* input, short* output, short len) {
	if (_changedFilter){
		for (int i = 0; i<FILTER_SIZE;++i){
			_firFilter[i] =_firFilterTemp[i];
		}

		fir_init(_filterState,_firFilter,_delayLine,FILTER_SIZE,0);
		_changedFilter = false;
	}
	fract* inputFract = (fract*) input;
	fract* outputFract = (fract*) output;

	fir_fx16(inputFract, outputFract, len, &_filterState);
/*	for (int i=0; i<len; ++i) {
		int k;
		accum y=0; // 9.31
		for
		// Use of circular pointer, new sample
		*_cir_ptr = inputFract[i]; // Input format short
		// Increment  pointer, step, start,  length
		_cir_ptr = (fract*) circptr((void*)_cir_ptr, sizeof(short), _delayLine, sizeof(short)*FILTER_SIZE);
		delay = _cir_ptr; // Points to oldest sample, cast to fract pointer
		// Convolution: h * x
		for(k=0; k < FILTER_SIZE; k++) {
			y += _firFilter[k] * (*delay);
			delay = (fract*) circptr((void*)delay, sizeof(short), _delayLine, sizeof(short)*FILTER_SIZE);
		}
		// convert format 9.31 -> 1.15 -> short
		outputFract[i] = y;
	}*/
}

void FirFilterAlgo::create() {
	fir_init(_filterState,_firFilter,_delayLine,FILTER_SIZE,0);
}

void FirFilterAlgo::create(fract* filter, int length) {
	for (int i = 0; i<FILTER_SIZE;
			++i){
		if (i<length){
			_firFilter[i] =filter[i];
		}else
			_firFilter[i] = 0;
	}
	fir_init(_filterState,_firFilter,_delayLine,FILTER_SIZE,0);
}

void FirFilterAlgo::modifyFilter(fract* filter, int length) {
	for (int i = 0; i<FILTER_SIZE;
			++i){
		if (i<length){
			_firFilterTemp[i] =filter[i];
		}else
			_firFilterTemp[i] = 0;
	}
//	fir_init(_filterStateTemp,_firFilterTemp,_delayLine,FILTER_SIZE,0);
	_changedFilter = true;
}
