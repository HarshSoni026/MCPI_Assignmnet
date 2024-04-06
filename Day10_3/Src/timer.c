/*
 * timer.c
 *
 *  Created on: Apr 4, 2024
 *      Author: Nilesh
 */

#include "timer.h"
#include "i2c_lcd.h"

#include "string.h"
#include "stdio.h"

char str1[32];
volatile int c=0;

void TimerInit(void) {
	// enable timer clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
	// set prescalar
	TIM7->PSC = TIM_PR-1;
	TIM7->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM7_IRQn);
	TIM7->CR1 |= TIM_CR1_CEN;
}

void TimerDelayMs(uint32_t ms) {
	// set number of clocks to count
	uint16_t cnt = (TCLK / 1000) * ms / TIM_PR;
	TIM7->ARR = cnt - 1;
	// start count from 0
	TIM7->CNT = 0;
	// start timer counter
	TIM7->CR1 |= TIM_CR1_CEN;
	// wait for update interrupt flag
	while(! (TIM7->SR & TIM_SR_UIF))
		;
	// clear the update interrupt flag
	TIM7->SR &= ~TIM_SR_UIF;
	// stop timer counter
	TIM7->CR1 &= ~TIM_CR1_CEN;
}

void TimerGenerateInterrupt(void) {
	TIM7->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM7_IRQn);
	NVIC_SetPriority(TIM7_IRQn,0);
}

void TIM7_IRQHandler(void)
{
	static int flag = 0;
	// check if interrupt occurred
	if(TIM7->SR & TIM_SR_UIF) {
		// then clear (ack) the interrupt
		TIM7->SR &= ~TIM_SR_UIF;
		// toggle LED
		if(flag == 0) {


			c++;
			sprintf(str1, "  %d",c);
			LcdPuts(LCD_LINE2, str1);

			flag = 1;
		} else {
			//LedOff(LED_BLUE);
			flag = 0;
		}
	}
}


