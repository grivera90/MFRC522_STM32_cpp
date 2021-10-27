/*
 * LED.h
 *
 *  Created on: Oct 21, 2021
 *      Author: Asus-TUF
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"

class LED {
public:

	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;

	LED(GPIO_TypeDef* gpio, uint16_t gpio_pin);
	virtual ~LED();

	void On();
	void Off();
	void Toggle();
};

#endif /* LED_H_ */
