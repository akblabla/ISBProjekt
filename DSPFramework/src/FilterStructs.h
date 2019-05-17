#ifndef FILTERSTRUCTS_H_
#define FILTERSTRUCTS_H_
#include <stdfix.h>
#define FILTER_SIZE 256
#define COEFFICIENTS 150
#define FILTERS 187
#define TRIANGLES 370

struct fractVector3d{
	fract x;
	fract y;
	fract z;
};
struct HRTFFilter{
	fract coefficients[COEFFICIENTS];
};
struct accumVector3d{
	accum x;
	#pragma align
	accum y;
	#pragma align
	accum z;
};
struct HRTFFilterHeader{
	fractVector3d orientation;
	#pragma align
	int delay;
	#pragma align
	HRTFFilter* filter;
};
struct filterTriangle{
	int filterIDs[3];
	#pragma align
	fractVector3d edges[3];
	#pragma align
	accum projectionMatrix[3][3];
};


	
#endif /* SOUNDFILTER3D_H_ */
