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
#include "mcu_stm32f7/gpio/mcu_gpio.h"

#include "bsp_f723_disco/lcd_st7789h2/lcd_st7789h2.h"


void MX_GPIO_Init();


mcu::GpioOutput led5;
mcu::GpioConfig led5Cfg = {	.port = LED5_GPIO_PORT,
				.pin = {	.Pin = LED5_PIN,
						.Mode = GPIO_MODE_OUTPUT_PP,
						.Pull = GPIO_NOPULL,
						.Speed = GPIO_SPEED_FREQ_LOW,
						.Alternate = 0},
				.activeState = emb::PinActiveState::HIGH};



int main()
{
	HAL_Init();
	mcu::initSystemClock();
	HAL_Delay(500);
	MX_GPIO_Init();

	led5.init(led5Cfg);
	
	bsp::LCD_st7789h2::init(&Font12);
	bsp::LCD_st7789h2::instance().print(0, "Hello world!");

	while (1)
	{
		led5.set();
		HAL_Delay(100);
		led5.reset();
		HAL_Delay(900);
		//HAL_GPIO_TogglePin(LED5_GPIO_PORT, LED5_PIN);
		//HAL_GPIO_TogglePin(LED6_GPIO_PORT, LED6_PIN);
		
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


