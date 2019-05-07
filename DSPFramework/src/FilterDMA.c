/*
 * FilterDMA.c
 *
 *  Created on: 23. apr. 2019
 *      Author: kasper
 */

#include "FilterDMA.h"

void Init_FilterDMA(void *src, void *dst)
{
	*pMDMA_S0_CONFIG = 0;
	*pMDMA_D0_CONFIG = 0;

	// configure MemDMA0 Source Descriptor block in memory
    *pMDMA_S0_START_ADDR = src;
    *pMDMA_S0_X_COUNT = 0x10;
    *pMDMA_S0_Y_COUNT = 0x2;
    *pMDMA_S0_X_MODIFY = 0x2;
    *pMDMA_S0_Y_MODIFY = 0x2;

    // configure MemDMA0 Destination Descriptor block in memory
    *pMDMA_D0_START_ADDR = dst;
    *pMDMA_D0_X_COUNT =0x10;
    *pMDMA_D0_Y_COUNT =0x2;
    *pMDMA_D0_X_MODIFY =0x2;
    *pMDMA_D0_Y_MODIFY =0x2;

	// enable MemDMA0 transfers
	// Stop mode and no interrupt enable required.
	*pMDMA_S0_CONFIG = DMAEN;  		 // 1D DMA Source read operation
	//*pMDMA_S0_CONFIG = 0x0071; //2D for source
	*pMDMA_D0_CONFIG = DMAEN | WNR;  // 1D DMA destination write operation
	//*pMDMA_D0_CONFIG = 0x0073;//2D for dest.

}

