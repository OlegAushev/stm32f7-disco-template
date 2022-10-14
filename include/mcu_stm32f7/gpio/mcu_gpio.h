/**
 * @file mcu_gpio.h
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once


#include "stm32f7xx_hal.h"
#include "emb/emb_interfaces/emb_gpio.h"


namespace mcu {


struct GpioConfig
{
	GPIO_TypeDef* port;
	GPIO_InitTypeDef pin;
	emb::PinActiveState activeState;
};


/*============================================================================*/
/**
 * @brief GPIO generic base class.
 */
class Gpio
{
protected:
	GpioConfig m_cfg;
	bool m_initialized;
	Gpio() : m_initialized(false) {}
public:
	/**
	 * @brief Returns reference to pin config.
	 * @param (none)
	 * @return Reference to pin config.
	 */
	const GpioConfig& config() const
	{
		return m_cfg;
	}

	static void enableClocks()
	{
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOD_CLK_ENABLE();
		__HAL_RCC_GPIOE_CLK_ENABLE();
		__HAL_RCC_GPIOF_CLK_ENABLE();
		__HAL_RCC_GPIOG_CLK_ENABLE();
		__HAL_RCC_GPIOH_CLK_ENABLE();
		__HAL_RCC_GPIOI_CLK_ENABLE();
	}
};


/*============================================================================*/
/**
 * @brief GPIO input pin class.
 */
class GpioInput : public emb::IGpioInput, public Gpio
{
public:
	/**
	 * @brief GPIO input pin default constructor.
	 * @param (none)
	 */
	GpioInput() {}

	/**
	 * @brief Constructs GPIO input pin.
	 * @param cfg - pin config
	 */
	GpioInput(const GpioConfig& cfg)
	{
		init(cfg);
	}

	/**
	 * @brief Initializes GPIO input pin.
	 * @param cfg - pin config
	 * @return (none)
	 */
	void init(const GpioConfig& cfg)
	{
		m_cfg = cfg;
		HAL_GPIO_Init(m_cfg.port, &m_cfg.pin);
		m_initialized = true;
	}

	/**
	 * @brief Reads pin state.
	 * @param (none)
	 * @return Pin state.
	 */
	virtual emb::PinState read() const override
	{
		assert_param(m_initialized);
		return static_cast<emb::PinState>(1
				- (HAL_GPIO_ReadPin(m_cfg.port, static_cast<uint16_t>(m_cfg.pin.Pin))
				^ static_cast<uint32_t>(m_cfg.activeState)));
	}
#ifdef  NOT_IMPLEMENTED
public:
	/**
	 * @brief Sets the pin for the specified external interrupt.
	 * @param intNum - interrupt number
	 * @return (none)
	 */
#ifdef CPU1
	void setInterrupt(GPIO_ExternalIntNum intNum)
	{
		GPIO_setInterruptPin(m_cfg.no, intNum);	// X-Bar may be configured on CPU1 only
	}
#endif

	/**
	 * @brief Registers interrupt handler.
	 * @param intNum - interrupt number
	 * @param intType - interrupt type
	 * @param handler - pointer to handler
	 */
	void registerInterruptHandler(GPIO_ExternalIntNum intNum, GPIO_IntType intType, void (*handler)(void))
	{
		m_intNum = intNum;
		GPIO_setInterruptType(intNum, intType);
		Interrupt_register(detail::PIE_XINT_NUMBERS[intNum], handler);
		Interrupt_enable(detail::PIE_XINT_NUMBERS[m_intNum]);
	}

	/**
	 * @brief Enables interrupts.
	 * @param (none)
	 * @return (none)
	 */
	void enableInterrupts() const
	{
		GPIO_enableInterrupt(m_intNum);

	}

	/**
	 * @brief Disables interrupts.
	 * @param (none)
	 * @return (none)
	 */
	void disableInterrupts() const
	{
		GPIO_disableInterrupt(m_intNum);
	}

	/**
	 * @brief Acknowledges interrupt.
	 * @param (none)
	 * @return (none)
	 */
	void acknowledgeInterrupt() const
	{
		Interrupt_clearACKGroup(detail::PIE_XINT_GROUPS[m_intNum]);
	}
#endif
};


/*============================================================================*/
/**
 * @brief GPIO output pin class.
 */
class GpioOutput : public emb::IGpioOutput, public Gpio
{
public:
	/**
	 * @brief GPIO output pin default constructor.
	 * @param (none)
	 */
	GpioOutput() {}

	/**
	 * @brief Constructs GPIO output pin.
	 * @param cfg - pin config
	 */
	GpioOutput(const GpioConfig& cfg)
	{
		init(cfg);
	}

	/**
	 * @brief Initializes GPIO output pin.
	 * @param cfg - pin config
	 * @return (none)
	 */
	void init(const GpioConfig& cfg)
	{
		m_cfg = cfg;
		HAL_GPIO_Init(m_cfg.port, &m_cfg.pin);
		m_initialized = true;
	}

	/**
	 * @brief Reads pin state.
	 * @param (none)
	 * @return Pin state.
	 */
	virtual emb::PinState read() const override
	{
		assert_param(m_initialized);
		return static_cast<emb::PinState>(1
				- (HAL_GPIO_ReadPin(m_cfg.port, static_cast<uint16_t>(m_cfg.pin.Pin))
				^ static_cast<uint32_t>(m_cfg.activeState)));
	}

	/**
	 * @brief Sets pin state.
	 * @param state - pin state
	 * @return (none)
	 */
	virtual void set(emb::PinState state = emb::PinState::ACTIVE) const override
	{
		assert_param(m_initialized);
		HAL_GPIO_WritePin(m_cfg.port, static_cast<uint16_t>(m_cfg.pin.Pin),
				static_cast<GPIO_PinState>(1 - (static_cast<uint32_t>(state) ^ static_cast<uint32_t>(m_cfg.activeState))));
	}

	/**
	 * @brief Sets pin state to INACTIVE.
	 * @param (none)
	 * @return (none)
	 */
	virtual void reset() const override
	{
		assert_param(m_initialized);
		set(emb::PinState::INACTIVE);
	}

	/**
	 * @brief Toggles pin state.
	 * @param (none)
	 * @return (none)
	 */
	virtual void toggle() const override
	{
		assert_param(m_initialized);
		HAL_GPIO_TogglePin(m_cfg.port, static_cast<uint16_t>(m_cfg.pin.Pin));
	}
};

















}


