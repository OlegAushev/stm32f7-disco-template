/**
 * @file main.cpp
 * @author Oleg Aushev (aushevom@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <string>
#include <sstream>

#include "build/generated/git_version.h"

#include "stm32f7xx_hal.h"
#include "stm32f723e_discovery.h"
#include "mcu_stm32f7/system/mcu_system.h"
#include "mcu_stm32f7/gpio/mcu_gpio.h"
#include "mcu_stm32f7/uart/mcu_uart.h"
#include "mcu_stm32f7/clock/mcu_clock.h"

#include "bsp_f723_disco/bsp_f723_disco_def.h"
#include "bsp_f723_disco/lcd_st7789h2/lcd_st7789h2.h"
#include "bsp_f723_disco/leds/leds.h"
#include "bsp_f723_disco/button/button.h"
#include "bsp_f723_disco/pmod/pmod.h"

#include "cli/cli_server.h"
#include "cli/shell/cli_shell.h"


/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
	const char* version = GIT_DESCRIBE;

	HAL_Init();
	mcu::initDeviceClock();
	HAL_Delay(500);
	mcu::gpio::enableClocks();

	MX_GPIO_Init();

	/* BSP */
	bsp::initLedRed();
	bsp::initLedGreen();
	bsp::initButtonWakeup();
	bsp::initPmod(bsp::PmodConfiguration::UART);
	
	bsp::LCD_st7789h2::init(&Font16);
	bsp::LCD_st7789h2::instance().print(0, version);

	/* UART */
	mcu::uart::RxPinConfig uart7RxPinCfg = {.port = PMOD3_RX_PORT, .pin = PMOD3_RX_PIN, .afSelection = GPIO_AF8_UART7};
	mcu::uart::TxPinConfig uart7TxPinCfg = {.port = PMOD2_TX_PORT, .pin = PMOD2_TX_PIN, .afSelection = GPIO_AF8_UART7};
	mcu::uart::Config uart7Cfg = {	.base = {	.BaudRate = 9600,
							.WordLength = UART_WORDLENGTH_8B,
							.StopBits = UART_STOPBITS_1,
							.Parity = UART_PARITY_NONE,
							.Mode = UART_MODE_TX_RX,
							.HwFlowCtl = UART_HWCONTROL_NONE},
					.advanced = {	.AdvFeatureInit = UART_ADVFEATURE_NO_INIT}};
	mcu::uart::Uart<7> uart7(uart7RxPinCfg, uart7TxPinCfg, uart7Cfg);

	/* CLI */
	cli::Server cliServer("stm32-disco", &uart7, nullptr, nullptr);
	cli::Shell::init();
	cliServer.registerExecCallback(cli::Shell::exec);
	cli::nextline_blocking();
	cli::nextline_blocking();
	cli::nextline_blocking();
	cli::print_blocking(CLI_WELCOME_STRING);

	/* CLOCK */
	mcu::SystemClock::init();

	/* TEST */
	bsp::buttonWakeup.initInterrupt(bsp::onButtonWakeupInterrupt, mcu::InterruptPriority(2));
	bsp::buttonWakeup.enableInterrupts();


	while (1)
	{
		mcu::SystemClock::runTasks();
		bsp::LCD_st7789h2::instance().print(1, std::to_string(mcu::SystemClock::now()).c_str());
		cliServer.run();
	}
}




/**
 * @brief 
 * 
 */
void bsp::onButtonWakeupInterrupt()
{
	bsp::LCD_st7789h2::instance().clearLine(2);
	if (bsp::buttonWakeup.read() == emb::PinState::ACTIVE)
	{
		bsp::LCD_st7789h2::instance().print(2, "pressed");
	}
	else
	{
		bsp::LCD_st7789h2::instance().print(2, "released");
	}
}


/**
 * @brief Fatal error callback.
 * 
 * @param hint 
 * @param code 
 */
void emb::fatal_error_cb(const char* hint, int code)
{
	cli::nextline_blocking();
	cli::print_blocking("Fatal error occurred: ");
	cli::print_blocking(hint);
	cli::nextline_blocking();
	cli::print_blocking("Terminate...");
	cli::nextline_blocking();
}


