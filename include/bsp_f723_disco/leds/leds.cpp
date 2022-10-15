/**
 * @file leds.cpp
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "leds.h"


namespace bsp {


mcu::gpio::Output ledRed;
const mcu::gpio::Config ledRedConfig = {	.port = LED5_GPIO_PORT,
					.pin = {.Pin = LED5_PIN,
						.Mode = GPIO_MODE_OUTPUT_PP,
						.Pull = GPIO_NOPULL,
						.Speed = GPIO_SPEED_FREQ_LOW,
						.Alternate = 0},
					.activeState = emb::PinActiveState::HIGH};


mcu::gpio::Output ledGreen;
const mcu::gpio::Config ledGreenConfig = {.port = LED6_GPIO_PORT,
					.pin = {.Pin = LED6_PIN,
						.Mode = GPIO_MODE_OUTPUT_PP,
						.Pull = GPIO_NOPULL,
						.Speed = GPIO_SPEED_FREQ_LOW,
						.Alternate = 0},
					.activeState = emb::PinActiveState::HIGH};
				

void initLedRed()
{
	ledRed.init(ledRedConfig);
}


void initLedGreen()
{
	ledGreen.init(ledGreenConfig);
}


} // namespace bsp


