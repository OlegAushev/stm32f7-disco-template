/**
 * @file button.cpp
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "button.h"


namespace bsp {


mcu::gpio::Input buttonWakeup;
const mcu::gpio::Config buttonWakeupConfig = {	.port = WAKEUP_BUTTON_GPIO_PORT,
						.pin = {.Pin = WAKEUP_BUTTON_PIN,
							.Mode = GPIO_MODE_IT_RISING_FALLING,
							.Pull = GPIO_NOPULL,
							.Speed = GPIO_SPEED_FREQ_LOW,
							.Alternate = 0},
						.activeState = emb::PinActiveState::HIGH};


void initButtonWakeup()
{
	buttonWakeup.init(buttonWakeupConfig);
}


__attribute__((weak)) void onButtonWakeupInterrupt()
{
	/* DO NOTHING */
}


} // namespace bsp


