/**
 * @file mcu_gpio.cpp
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "mcu_gpio.h"


std::array<std::function<void(void)>, 16> mcu::GpioInput::s_interruptHandlers = {
	emb::invalidFunction, emb::invalidFunction, emb::invalidFunction, emb::invalidFunction,
	emb::invalidFunction, emb::invalidFunction, emb::invalidFunction, emb::invalidFunction,
	emb::invalidFunction, emb::invalidFunction, emb::invalidFunction, emb::invalidFunction,
	emb::invalidFunction, emb::invalidFunction, emb::invalidFunction, emb::invalidFunction,
};


/**
 * @brief 
 * 
 * @param (none)
 * @return (none)
 */
extern "C" void EXTI0_IRQHandler(void)
{
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
	mcu::GpioInput::onInterrupt(0);
}


/**
 * @brief 
 * 
 * @param (none)
 * @return (none)
 */
extern "C" void EXTI1_IRQHandler(void)
{
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
	mcu::GpioInput::onInterrupt(1);
}


/**
 * @brief 
 * 
 * @param (none)
 * @return (none)
 */
extern "C" void EXTI2_IRQHandler(void)
{
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_2);
	mcu::GpioInput::onInterrupt(2);
}


/**
 * @brief 
 * 
 * @param (none)
 * @return (none)
 */
extern "C" void EXTI3_IRQHandler(void)
{
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);
	mcu::GpioInput::onInterrupt(3);
}


/**
 * @brief 
 * 
 * @param (none)
 * @return (none)
 */
extern "C" void EXTI4_IRQHandler(void)
{
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_4);
	mcu::GpioInput::onInterrupt(4);
}


/**
 * @brief 
 * 
 * @param (none)
 * @return (none)
 */
extern "C" void EXTI9_5_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);	
}


/**
 * @brief 
 * 
 * @param (none)
 * @return (none)
 */
extern "C" void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_12);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_14);
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
}


/**
 * @brief 
 * 
 * @param GPIO_Pin 
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	mcu::GpioInput::onInterrupt(POSITION_VAL(GPIO_Pin));
}


