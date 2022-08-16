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
#include "stm32f723e_discovery.h"
#include "mcu_stm32f7/system/mcu_system.h"


void MX_GPIO_Init();


int main()
{
	HAL_Init();
	mcu::initSystemClock();
	HAL_Delay(500);
	MX_GPIO_Init();

	float a = 1.f;
	float b = 42.2f;
	volatile float c = a + b;

	HAL_GPIO_TogglePin(LED6_GPIO_PORT, LED6_PIN);
	
	while (1)
	{
		c += 1;
		HAL_GPIO_TogglePin(LED5_GPIO_PORT, LED5_PIN);
		HAL_GPIO_TogglePin(LED6_GPIO_PORT, LED6_PIN);
		
		HAL_Delay(500);
	}
}



extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}