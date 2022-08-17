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

#include "bsp/lcd_st7789h2/lcd_st7789h2.h"


void MX_GPIO_Init();


int main()
{
	HAL_Init();
	mcu::initSystemClock();
	HAL_Delay(500);
	MX_GPIO_Init();
	
	bsp::LCD_st7789h2::init(&Font12);
	bsp::LCD_st7789h2::instance().print(0, "Hello world!");

	while (1)
	{

		HAL_GPIO_TogglePin(LED5_GPIO_PORT, LED5_PIN);
		HAL_GPIO_TogglePin(LED6_GPIO_PORT, LED6_PIN);
		
		HAL_Delay(500);
	}
}


/**
 * @brief Mandatory HAL-lib tick handler.
 * 
 */
extern "C" void SysTick_Handler(void)
{
	HAL_IncTick();
}


