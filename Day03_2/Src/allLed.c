#include "allLed.h"
#include "stm32f4xx.h"

void LedInit(uint32_t pin) {

	RCC->AHB1ENR |= BV(LED_GPIO_EN);
	LED_GPIO->MODER &= ~BV(pin * 2 + 1);
	LED_GPIO->MODER |= BV(pin * 2);
	LED_GPIO->OSPEEDR &= ~(BV(pin * 2 + 1) | BV(pin * 2));
	LED_GPIO->PUPDR &= ~(BV(pin * 2 + 1) | BV(pin * 2));

	LED_GPIO->OTYPER &= ~BV(pin);
}

void LedOn(uint32_t pin) {

	LED_GPIO->BSRR = BV(pin);
}

void LedOff(uint32_t pin) {

	LED_GPIO->BSRR = BV(pin + 16);
}

void LedBlink(uint32_t pin, uint32_t delay) {
	LedOn(pin);
	DelayMs(delay);
	LedOff(pin);
}
 void AllLedOn(){
	 LedOn(LED_BLUE);
	 LedOn(LED_GREEN);
	 LedOn(LED_RED);
	 LedOn(LED_ORANGE);

 }
 void AllLedOff(){
	 LedOff(LED_BLUE);
	 LedOff(LED_GREEN);
	 LedOff(LED_RED);
	 LedOff(LED_ORANGE);

 }








