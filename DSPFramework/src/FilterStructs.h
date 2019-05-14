#ifndef FILTERSTRUCTS_H_
#define FILTERSTRUCTS_H_
#include <stdfix.h>
#define FILTER_SIZE 256
#define COEFFICIENTS 150

struct fractVector3d{
	fract x;
	fract y;
	fract z;
};
struct HRTFFilter{
	fract filter[COEFFICIENTS];
};
struct HRTFFilterHeader{
	fractVector3d orientation;
	int delay;
	HRTFFilter* filter;
};
struct filterTriangle{
	HRTFFilterHeader* filters[3];
	fractVector3d edges[3];
	accum projectionMatrix[3][3];
};
struct accumVector3d{
	accum x;
	accum y;
	accum z;
};

	
#endif /* SOUNDFILTER3D_H_ */
