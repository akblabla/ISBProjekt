/*
 * FilterDMA.c
 *
 *  Created on: 23. apr. 2019
 *      Author: kasper
 */

#include "FilterDMA.h"
#define COEFFICIENTS 150
DMADestriptor makeDMADescriptor(void *addr, DMADestriptor* nextDesc, bool write, bool end)
{
	DMADestriptor desc;
	// configure MemDMA0 Source Descriptor block in memory
	if (end)
		desc.pNext = 0;
	else
		desc.pNext = nextDesc;
	desc.pStart = addr;
	desc.dXModify = 0x4;
	desc.dYModify = 0x0;
	desc.dXCount = COEFFICIENTS;
	desc.dYCount = 0x0;
	desc.dConfig = 0x0;

	// Stop mode and no interrupt enable required.
	unsigned short FLOWSetting = 0x7; //restart using next descriptor
	unsigned short NDSizeSetting = 0x9; //load full descriptor
	unsigned short WDSIZESetting = 0x8; //32 bit transfer

	if (write)
		desc.dConfig = DMAEN | WNR;  // 1D DMA destination write operation
	else
		desc.dConfig= DMAEN;  		 // 1D DMA Source read operation
	if (!end)
		desc.dConfig |= FLOWSetting | NDSizeSetting | WDSIZESetting;
}



void startFilterDMA(void *src, void *dst, DMADestriptor* nextSrcDesc, DMADestriptor* nextDstDesc)
{
	*pMDMA_S0_CONFIG = 0;
	*pMDMA_D0_CONFIG = 0;

	// configure MemDMA0 Source Descriptor block in memory
    *pMDMA_S0_NEXT_DESC_PTR = nextSrcDesc;
    *pMDMA_S0_START_ADDR = src;
    *pMDMA_S0_X_MODIFY = 0x4;
    *pMDMA_S0_X_COUNT = COEFFICIENTS;

    // configure MemDMA0 Destination Descriptor block in memory
    *pMDMA_D0_NEXT_DESC_PTR = nextDstDesc;
    *pMDMA_D0_START_ADDR = dst;
    *pMDMA_D0_X_MODIFY =0x4;
    *pMDMA_D0_X_COUNT = COEFFICIENTS;

	// enable MemDMA0 transfers
	// Stop mode and no interrupt enable required.
	unsigned short FLOWSetting = 0x7; //restart using next descriptor
	unsigned short NDSizeSetting = 0x9; //load full descriptor
	unsigned short WDSIZESetting = 0x8; //32 bit transfer

    *pMDMA_S0_CONFIG = DMAEN | FLOWSetting | NDSizeSetting | WDSIZESetting;  		 // 1D DMA Source read operation
	//*pMDMA_S0_CONFIG = 0x0071; //2D for source
	*pMDMA_D0_CONFIG = DMAEN | WNR | FLOWSetting | NDSizeSetting | WDSIZESetting;  // 1D DMA destination write operation
	//*pMDMA_D0_CONFIG = 0x0073;//2D for dest.
}

void startFilterDMASingle(void *src, void *dst)
{
	*pMDMA_S0_CONFIG = 0;
	*pMDMA_D0_CONFIG = 0;

	// configure MemDMA0 Source Descriptor block in memory
    *pMDMA_S0_START_ADDR = src;
    *pMDMA_S0_X_MODIFY = 0x4;
    *pMDMA_S0_X_COUNT = COEFFICIENTS;

    // configure MemDMA0 Destination Descriptor block in memory
    *pMDMA_D0_START_ADDR = dst;

    *pMDMA_D0_X_MODIFY =0x4;
    *pMDMA_D0_X_COUNT = COEFFICIENTS;

	unsigned short WDSIZESetting = 0x8; //32 bit transfer

	// enable MemDMA0 transfers
	// Stop mode and no interrupt enable required.
	*pMDMA_S0_CONFIG = DMAEN | WDSIZESetting;  		 // 1D DMA Source read operation
	//*pMDMA_S0_CONFIG = 0x0071; //2D for source
	*pMDMA_D0_CONFIG = DMAEN | WNR | WDSIZESetting;  // 1D DMA destination write operation
	//*pMDMA_D0_CONFIG = 0x0073;//2D for dest.
}
