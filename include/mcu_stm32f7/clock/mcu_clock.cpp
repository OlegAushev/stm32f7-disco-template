/**
 * @file mcu_clock.cpp
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "mcu_clock.h"


/**
 * @brief Mandatory HAL-lib tick handler.
 * 
 */
extern "C" void SysTick_Handler()
{
	HAL_IncTick();
	mcu::SystemClock::onInterrupt();
}


namespace mcu {


void SystemClock::init()
{
	m_taskPeriods.fill(0);
	m_taskTimestamps.fill(0);
	m_tasks.fill(emptyTask);
	
	setInitialized();
}


} // namespace mcu


