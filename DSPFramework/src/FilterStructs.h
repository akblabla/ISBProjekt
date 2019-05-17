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
	#pragma align(4)
	accum y;
	#pragma align(4)
	accum z;
};
struct HRTFFilterHeader{
	fractVector3d orientation;
	#pragma align(4)
	int delay;
	#pragma align(4)
	HRTFFilter* filter;
};
struct filterTriangle{
	int filterIDs[3];
	#pragma align(4)
	fractVector3d edges[3];
	#pragma align(4)
	accum projectionMatrix[3][3];
};


	
#endif /* SOUNDFILTER3D_H_ */
