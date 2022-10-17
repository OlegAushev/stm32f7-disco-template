/**
 * @defgroup mcu MCU
 *
 * @defgroup mcu_system System
 * @ingroup mcu
 * 
 * @file mcu_system.h
 * @ingroup mcu mcu_system
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once


#include "../mcu_def.h"


void MX_GPIO_Init();


namespace mcu {
/// @addtogroup mcu_system
/// @{


/**
 * @brief Initializes device clock.
 * 
 * @param (none)
 * @return (none) 
 */
void initDeviceClock();


/**
 * @brief Resets device.
 * 
 */
void resetDevice();


/**
 * @brief On fatal error callback.
 * 
 * @param (none)
 * @return (none) 
 */
void onFatalError();


/**
 * @brief Delays for a number of milliseconds.
 * 
 * @param delay delay in milliseconds
 * @return (none)
 */
inline void delay_ms(uint32_t delay)
{
	HAL_Delay(delay);
}


/// @}
} // namespace mcu


