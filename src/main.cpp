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


#include <sstream>
#include "emb/emb_algorithm.h"
#include "emb/emb_string.h"

#include "build/generated/git_version.h"

#include "stm32f7xx_hal.h"
#include "stm32f723e_discovery.h"
#include "mcu_stm32f7/system/mcu_system.h"
#include "mcu_stm32f7/gpio/mcu_gpio.h"

#include "bsp_f723_disco/lcd_st7789h2/lcd_st7789h2.h"
#include "bsp_f723_disco/leds/leds.h"
#include "bsp_f723_disco/button/button.h"


void MX_GPIO_Init();




int main()
{
	const char* version = GIT_DESCRIBE;

	HAL_Init();
	mcu::initSystemClock();
	HAL_Delay(500);
	mcu::Gpio::enableClocks();

	MX_GPIO_Init();

	bsp::initLedRed();
	bsp::initLedGreen();
	bsp::initWakeupButton();
	
	bsp::LCD_st7789h2::init(&Font16);
	bsp::LCD_st7789h2::instance().print(0, version);

	std::stringstream sstr;
	sstr << "red: " << bsp::ledRed.no() << "; green: " << bsp::ledGreen.no();
	bsp::LCD_st7789h2::instance().print(1, sstr.str().c_str());
	
	bsp::wakeupButton.initInterrupt(bsp::onWakeupButtonInterrupt, mcu::InterruptPriority(2));
	bsp::wakeupButton.enableInterrupts();

	while (1)
	{
		bsp::ledRed.set();
		bsp::ledGreen.reset();
		mcu::delay_ms(100);
		bsp::ledRed.reset();
		bsp::ledGreen.set();
		mcu::delay_ms(900);
	}
}




void bsp::onWakeupButtonInterrupt()
{
	bsp::LCD_st7789h2::instance().clearLine(2);
	if (bsp::wakeupButton.read() == emb::PinState::ACTIVE)
	{
		bsp::LCD_st7789h2::instance().print(2, "pressed");
	}
	else
	{
		bsp::LCD_st7789h2::instance().print(2, "released");
	}
}
