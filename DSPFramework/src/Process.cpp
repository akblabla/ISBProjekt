///////////////////////////////////////////////////////////
//  Process.cpp
//  Implementation of Process
//  Created on:      06-aug-2014 09:30:58
//  Original author: kbe
///////////////////////////////////////////////////////////
#include "Algorithm.h"
#include "RegisterManager.h"
#include <cycle_count.h>
#include <stdio.h>

Algorithm *pAlgoLeft;
Algorithm *pAlgoRight;

void InitProcess(Algorithm *left, Algorithm *right)
{
	pAlgoLeft = left;
	pAlgoRight = right;
}

extern "C" {

	// Interface to SPORT interrupt
	void Process(void)
	{
		/* Not used - extra channel Ch1 left/right
		int i;
		for (i=0; i<INPUT_SIZE; i++)
		{
			sCh1LeftOut[i] = sCh1LeftIn[i];
			sCh1RightOut[i] = sCh1RightIn[i];
		}
		*/
		cycle_t start_count;
		cycle_t final_count;
		START_CYCLE_COUNT(start_count);
		pAlgoLeft->process(sCh0LeftIn, sCh0LeftOut, INPUT_SIZE);
		pAlgoRight->process(sCh0LeftIn, sCh0RightOut, INPUT_SIZE);
		STOP_CYCLE_COUNT(final_count,start_count);
		PRINT_CYCLES("Number of cycles per block of 512 samples: ", final_count);
	
	}

}
