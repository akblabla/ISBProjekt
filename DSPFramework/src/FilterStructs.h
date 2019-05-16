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
	fract filter[COEFFICIENTS];
};
struct accumVector3d{
	accum x;
	accum y;
	accum z;
};
struct HRTFFilterHeader{
	accumVector3d orientation;
	int delay;
	HRTFFilter* filter;
};
struct filterTriangle{
	int filterIDs[3];
	accumVector3d edges[3];
	accum projectionMatrix[3][3];
};


	
#endif /* SOUNDFILTER3D_H_ */
