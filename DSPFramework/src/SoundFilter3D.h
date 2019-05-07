/*
 * SoundFilter3D.h
 *
 *  Created on: 30. apr. 2019
 *      Author: kaspe
 */

#ifndef SOUNDFILTER3D_H_
#define SOUNDFILTER3D_H_
#include <stdfix.h>
#define FIR_SIZE 150
	struct fractVector3d{
		fract x;
		fract y;
		fract z;		
	};
	struct HRTFFilter{
		fract filter[FIR_SIZE];
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
class SoundFilter3D {
public:
	SoundFilter3D();
	virtual ~SoundFilter3D();
	void makeFilter(fract* filter, fractVector3d orientation);

private:
	
	fractVector3d normalize(accumVector3d vector);
	void interpolateFilter(fract* filterOut, fract*a, fract*b, fract*c, fractVector3d weights);
	fractVector3d findWeights(filterTriangle triangle, fractVector3d orientation);
	void loadFilters(filterTriangle triangle);
	filterTriangle findFilterTriangle(fractVector3d orientation);
	
	filterTriangle getFilterTriangle(int ID);
	fractVector3d getFilterOrientationVector(int filterIDs);
	
	fract filterBuffer[FIR_SIZE][3][2];
	fract* readyBuffer[3];
	fract* loadingBuffer[3];
	section("sdram0_bank0") volatile short filterDMA0_Src_Array[FIR_SIZE];
	volatile short filterDMA0_Dst_Array[FIR_SIZE];

};

#endif /* SOUNDFILTER3D_H_ */
