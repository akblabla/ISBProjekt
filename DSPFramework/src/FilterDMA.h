///////////////////////////////////////////////////////////////////////////////
//
// 	
//  Experiment 7.4 talk-through program using BF533 EZ-KIT
//  FILE name: HAL.h
//
//  Description: Talk-through program with different CODEC settings
//		 C header file containing prototypes and macros
//  
//  For the book "Embedded Signal Processing with the Micro Signal Architecture"
//		  By Woon-Seng Gan and Sen M. Kuo
//		  Publisher: John Wiley and Sons, Inc.
//
//  Tools used: VisualDSP++ v4.0 (running on BF533 EZ-KIT)
//  Modified: 6/8-2014 - KBE
//
///////////////////////////////////////////////////////////////////////////////

#include "RegisterManager.h"

//Necessary variable declaration
#ifndef __FILTER_DMA_DEFINED
	#define __FILTER_DMA_DEFINED
	
//#define _USE_LEGACY_CDEF_BEHAVIOUR
#include <sys\exception.h>
#include <cdefBF533.h>
//#include "FilterStructs.h"


typedef struct {
	void *pNext;
	void *pStart;
	short dConfig;
	short dXCount;
	short dXModify;
	short dYCount;
	short dYModify;
} DMADestriptor;

extern "C" {
	//Buffer from/to Codec1836
	DMADestriptor makeDMADescriptor(void *addr, DMADestriptor* nextDesc, bool write, bool end);
	void startFilterDMA(void *src, void *dst, DMADestriptor* nextSrcDesc, DMADestriptor* nextDstDesc);
	void startFilterDMASingle(void *src, void *dst);
};

#endif
