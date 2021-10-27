/*
 * LED.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: Asus-TUF
 */

#include "LED.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"

LED::LED(GPIO_TypeDef* gpio, uint16_t gpio_pin) {
	// TODO Auto-generated constructor stub
	GPIOx = gpio;
	GPIO_Pin = gpio_pin;
}

LED::~LED() {
	// TODO Auto-generated destructor stub
}

void LED::On()
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
}

void LED::Off()
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

void LED::Toggle()
{
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}
