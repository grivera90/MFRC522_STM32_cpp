/*
 * main_app.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: Asus-TUF
 */
#include "main.h"
#include "LED.h"
#include "MFRC522.h"
#include <stdio.h>

uint8_t uid_size = 0;
uint16_t delay = 0;
char buffer[256];
int buffer_size = 0;

extern UART_HandleTypeDef huart1;

LED myLed(LED_GPIO_Port, LED_Pin);

void blink_led(uint16_t delay);

void main_cpp()
{
	//this is our main for cpp part of code.
	MFRC522 myMFRC522class;

	  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
	  MFRC522::MIFARE_Key key;
	  for (uint8_t i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

	  //some variables we need
	  uint8_t block;
	  uint8_t len;
	  MFRC522::StatusCode status;

	myMFRC522class.PCD_Init();
	HAL_Delay(5);

	myMFRC522class.PCD_DumpVersionToSerial();
	buffer_size = sprintf(buffer, "Scan PICC to see UID, SAK, type, and data blocks...");
	HAL_UART_Transmit(&huart1, (uint8_t *) buffer, buffer_size, 100);

	while(1)
	{

		if (myMFRC522class.PICC_IsNewCardPresent())
		{
			if(myMFRC522class.PICC_ReadCardSerial())
			{
				myMFRC522class.PICC_DumpDetailsToSerial(&(myMFRC522class.uid));
				//myMFRC522class.PICC_DumpToSerial(&(myMFRC522class.uid));
			}
		}

		blink_led(100);
	}
}


void blink_led(uint16_t delay)
{
	uint8_t i = 0;

	for(i = 0; i < 5; i++)
	{
		myLed.On();
		HAL_Delay(delay);
		myLed.Off();
		HAL_Delay(delay);
	}
}

