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

struct longFractVector3d{
	long fract x;
	long fract y;
	long fract z;
};

struct HRTFFilter{
	int filterID;
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
	int filterID;
	fractVector3d orientation;
	int delay;
};
struct filterTriangle{
	int triangleID;
	int filterIDs[3];
	longFractVector3d edges[3];
	accum projectionMatrix[3][3];
};


	
#endif /* SOUNDFILTER3D_H_ */
