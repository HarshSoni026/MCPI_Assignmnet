#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "allLed.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void)
{
	SystemInit();
	DelayMs(1);
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);
	while(1) {


		AllLedOn();
		DelayMs(500);
		AllLedOff();
		DelayMs(500);
	}
	return 0;
}

