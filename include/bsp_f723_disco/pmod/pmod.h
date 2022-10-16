/**
 * @file pmod.h
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once


#include "stm32f723e_discovery.h"
#include "mcu_stm32f7/gpio/mcu_gpio.h"


#define PMOD_SEL_0_PORT		GPIOH
#define PMOD_SEL_0_PIN		GPIO_PIN_15
#define PMOD_SEL_1_PORT		GPIOI
#define PMOD_SEL_1_PIN		GPIO_PIN_10


namespace bsp {


enum class PmodConfiguration
{
	SPI,
	UART_SPI,
	UART
};


extern mcu::gpio::Output pmodSel0;
extern const mcu::gpio::Config pmodSel0Config;


extern mcu::gpio::Output pmodSel1;
extern const mcu::gpio::Config pmodSel1Config;


void initPmod(PmodConfiguration cfg);


} // namespace bsp


