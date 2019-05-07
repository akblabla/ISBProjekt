/*
 * SpatialSoundAlgo.cpp
 *
 *  Created on: 23. apr. 2019
 *      Author: kaspe
 */

#include "SpatialSoundAlgo.h"


SpatialSoundAlgo::SpatialSoundAlgo() {


}
float y = 0;
SpatialSoundAlgo::~SpatialSoundAlgo() {
	// TODO Auto-generated destructor stub
}

void SpatialSoundAlgo::process(short* input, short* output, short len) {
	// convolve
	//void convolve_fr32(const fract32 input_x[], int length_x, const fract32 input_y[], int length_y, fract32 output[]);
	fract* inputFract = (fract*) input;
	fract* outputFract = (fract*) output;
	//convolve_fx16(inputFract, (int) len, _firFilter, FIR_SIZE, outputFract);
	fir_fx16(inputFract, outputFract, len, &_filterState);

}

void SpatialSoundAlgo::create(void) {
	for (int i = 0; i<FIR_SIZE; ++i){

		_firFilter[i] =1.0/FIR_SIZE;
	}

	fir_init(_filterState,_firFilter,_delayLine,FIR_SIZE,0);
}

//taken from quake 3 arena
float SpatialSoundAlgo::fastInverseSquare(float input){
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = input * 0.5F;
	y  = input;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration

	return y;
}
