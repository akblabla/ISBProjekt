///////////////////////////////////////////////////////////////////////////////
//
// 	DSP Design Framework (C++) for stereo 16 bit sample block processing
//  Prepared for a dynamic notch filter controlled by FFT analysis (N=1024)
//  
//  Main program and initialization
//
//  13. marts. 2018 KBE
///////////////////////////////////////////////////////////////////////////////
#include "stdio.h"
#include "sysreg.h"  //definition of reg_SYSCFG
#include "ccblkfn.h" //definition of built-in function
					 //  in this program:sysreg_write()
#include "Controller.h"
#include "AlgoTester.h"
#include "FirFilterAlgo.h"
#include "RegisterManager.h"

// Initialization of sample block processing inputs
void InitProcess(Algorithm *left, Algorithm *right);
// Initialization of control for switch inputs
void InitSwitch(Controller *ctrl);

FirFilterAlgo leftAlgo;
FirFilterAlgo rightAlgo;

// Instance of dummy algorithm for left and right stereo channels

// Instance of controller left and right
Controller Ctrl(&leftAlgo,&rightAlgo);

void InitAlgoProcess(void)
{
	leftAlgo.create();
	rightAlgo.create();
	InitSwitch(&Ctrl);
}

void InitSystemHardware(void)
{
	ucLED = 0x3F; // Turn all LEDs on

	Init_EBIU();
	Init_LED();
	Init_1836();
	Init_Sport();
	Init_DMA();
	Init_PF();
	Init_Timer();
}

void main(void)
{
	sysreg_write(reg_SYSCFG, 0x32); //Enable 64-bit,free-running cycle-counter
									//BF533 Hardware Reference pg 4-6 NB!!!
	InitSystemHardware(); // Initialization of BF533
	InitAlgoProcess(); // Initialization of processing algorithms
	InitProcess(&leftAlgo,&rightAlgo);
	Ctrl.init();
	Init_Interrupt(); // Enable interrupts
	Enable_DMA();
	while(1)
	{
		// TODO insert background processing code as necessary
	}; // wait forever
}
