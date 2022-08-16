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


#include "stm32f7xx_hal.h"


namespace mcu {
/// @addtogroup mcu_system
/// @{


void initSystemClock();
void onFatalError();

/// @}
} // namespace mcu

