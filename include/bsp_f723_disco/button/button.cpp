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


mcu::GpioInput wakeupButton;
const mcu::GpioConfig wakeupButtonConfig = {	.port = WAKEUP_BUTTON_GPIO_PORT,
						.pin = {.Pin = WAKEUP_BUTTON_PIN,
							.Mode = GPIO_MODE_IT_RISING_FALLING,
							.Pull = GPIO_NOPULL,
							.Speed = GPIO_SPEED_FREQ_LOW,
							.Alternate = 0},
						.activeState = emb::PinActiveState::HIGH};


void initWakeupButton()
{
	wakeupButton.init(wakeupButtonConfig);
}


__weak void onWakeupButtonInterrupt()
{
	/* DO NOTHING */
}


} // namespace bsp


