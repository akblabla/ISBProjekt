/*
 * SoundFilter3D.h
 *
 *  Created on: 30. apr. 2019
 *      Author: kaspe
 */

#ifndef SOUNDFILTER3D_H_
#define SOUNDFILTER3D_H_
#include <stdfix.h>
#define FIR_SIZE 256

struct fractVector3d{
	fract x;
	fract y;
	fract z;
};
struct accumMatrix3_3{
	accum value[3][3];
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
	fractVector3d findWeights(int* filterIDs, fractVector3d orientation);
	void loadFilter(int* filterIDs);
	void filterSearch(int* filterIDs, fractVector3d orientation);
	
	accumMatrix3_3 getProjectionMatrix(int* filterIDs);
	fractVector3d getFilterOrientationVector(int filterIDs);
	
	fract filterBuffer[FIR_SIZE][3][2];
	fract* readyBuffer[3];
	fract* loadingBuffer[3];
	
};

#endif /* SOUNDFILTER3D_H_ */
