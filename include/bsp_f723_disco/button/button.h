/**
 * @file button.h
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once


#include "stm32f723e_discovery.h"
#include "mcu_stm32f7/gpio/mcu_gpio.h"


namespace bsp {


extern mcu::gpio::Input buttonWakeup;
extern const mcu::gpio::Config buttonWakeupConfig;
void initButtonWakeup();
void onButtonWakeupInterrupt();


} // namespace bsp


