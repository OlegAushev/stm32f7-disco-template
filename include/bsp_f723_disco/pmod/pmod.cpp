/**
 * @file pmod.cpp
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "pmod.h"


namespace bsp {


mcu::gpio::Output pmodSel0;
const mcu::gpio::Config pmodSel0Config = {	.port = PMOD_SEL_0_PORT,
						.pin = {.Pin = PMOD_SEL_0_PIN,
							.Mode = GPIO_MODE_OUTPUT_PP,
							.Pull = GPIO_NOPULL,
							.Speed = GPIO_SPEED_FREQ_LOW,
							.Alternate = 0},
						.activeState = emb::PinActiveState::HIGH};

mcu::gpio::Output pmodSel1;
const mcu::gpio::Config pmodSel1Config = {	.port = PMOD_SEL_1_PORT,
						.pin = {.Pin = PMOD_SEL_1_PIN,
							.Mode = GPIO_MODE_OUTPUT_PP,
							.Pull = GPIO_NOPULL,
							.Speed = GPIO_SPEED_FREQ_LOW,
							.Alternate = 0},
						.activeState = emb::PinActiveState::HIGH};


void initPmod(PmodConfiguration cfg)
{
	pmodSel0.init(pmodSel0Config);
	pmodSel1.init(pmodSel1Config);

	switch (cfg)
	{
	case PmodConfiguration::SPI:
		pmodSel0.reset();
		pmodSel1.reset();
		break;
	case PmodConfiguration::UART_SPI:
		pmodSel0.set();
		pmodSel1.reset();
		break;
	case PmodConfiguration::UART:
		pmodSel0.set();
		pmodSel1.set();
		break;
	}
}


} // namespace bsp


