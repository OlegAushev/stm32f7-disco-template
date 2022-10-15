/**
 * @file mcu_uart.h
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once


#include "emb/emb_interfaces/emb_uart.h"

#include "stm32f7xx_hal.h"
#include "../mcu_def.h"
#include "../system/mcu_system.h"


namespace mcu {


namespace uart {


struct RxPinConfig
{
	uint32_t pin;
	uint32_t afSelection;
};


struct TxPinConfig
{
	uint32_t pin;
	uint32_t afSelection;
};


struct Config
{
	UART_InitTypeDef base;
	UART_AdvFeatureInitTypeDef advanced;
};


template <USART_TypeDef* Module>
class Uart : public emb::IUart
{
private:
	UART_HandleTypeDef m_handle;
public:
	Uart(const RxPinConfig& rxPinCfg, TxPinConfig txPinConfig, const Config& cfg)
	{
		if constexpr (Module == USART1) { __HAL_RCC_USART1_CLK_ENABLE(); }
		else if constexpr (Module == USART2) { __HAL_RCC_USART2_CLK_ENABLE(); }
		else if constexpr (Module == USART3) { __HAL_RCC_USART3_CLK_ENABLE(); }
		else if constexpr (Module == UART4) { __HAL_RCC_UART4_CLK_ENABLE(); }
		else if constexpr (Module == UART5) { __HAL_RCC_UART5_CLK_ENABLE(); }
		else if constexpr (Module == USART6) { __HAL_RCC_USART6_CLK_ENABLE(); }
		else if constexpr (Module == UART7) { __HAL_RCC_UART7_CLK_ENABLE(); }
		else if constexpr (Module == UART8) { __HAL_RCC_UART8_CLK_ENABLE(); }
		else { onFatalError(); }

		m_handle.Instance = Module;
		m_handle.Init = cfg.base;
		m_handle.AdvancedInit = cfg.advanced;
		if (HAL_UART_Init(&m_handle) != HAL_OK)
		{
			onFatalError();
		}
	}
};


} // namespace uart


} // namespace mcu


