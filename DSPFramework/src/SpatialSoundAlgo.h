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

#define FIR_SIZE 100

class SpatialSoundAlgo : public Algorithm {
public:
	SpatialSoundAlgo();
	virtual ~SpatialSoundAlgo();

	virtual void process(short* input, short* output, short len);
	virtual void create(void);

	float fastInverseSquare(float input);
	fract _firFilter[FIR_SIZE];
	fract _delayLine[FIR_SIZE];
	fir_state_fx16 _filterState;

};

#endif /* SPATIALSOUNDALGO_H_ */
