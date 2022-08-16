/**
 * @file main.cpp
 * @author Oleg Aushev (aushevom@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "stm32f7xx_hal.h"
#include "mcu_stm32f7/system/mcu_system.h"


int main()
{
	HAL_Init();
	mcu::initSystemClock();
	HAL_Delay(500);

	float a = 1.f;
	float b = 42.2f;
	float c = a + b;

	while (1)
	{

		HAL_Delay(500);
	}
}


