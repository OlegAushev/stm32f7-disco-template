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


#include "build/generated/git_version.h"

#include "stm32f7xx_hal.h"
#include "stm32f723e_discovery.h"
#include "mcu_stm32f7/system/mcu_system.h"
#include "mcu_stm32f7/gpio/mcu_gpio.h"

#include "bsp_f723_disco/lcd_st7789h2/lcd_st7789h2.h"
#include "bsp_f723_disco/leds/leds.h"


void MX_GPIO_Init();


int main()
{
	
	const char* version = GIT_DESCRIBE;

	HAL_Init();
	mcu::initSystemClock();
	HAL_Delay(500);
	MX_GPIO_Init();

	bsp::initLedRed();
	bsp::initLedGreen();
	
	bsp::LCD_st7789h2::init(&Font12);
	bsp::LCD_st7789h2::instance().print(0, version);

	while (1)
	{
		bsp::ledRed.set();
		bsp::ledGreen.reset();
		HAL_Delay(100);
		bsp::ledRed.reset();
		bsp::ledGreen.set();
		HAL_Delay(900);	
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


