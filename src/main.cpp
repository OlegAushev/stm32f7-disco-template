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


#include <sstream>

#include "build/generated/git_version.h"

#include "stm32f7xx_hal.h"
#include "stm32f723e_discovery.h"
#include "mcu_stm32f7/system/mcu_system.h"
#include "mcu_stm32f7/gpio/mcu_gpio.h"
#include "mcu_stm32f7/uart/mcu_uart.h"

#include "bsp_f723_disco/bsp_f723_disco_def.h"
#include "bsp_f723_disco/lcd_st7789h2/lcd_st7789h2.h"
#include "bsp_f723_disco/leds/leds.h"
#include "bsp_f723_disco/button/button.h"
#include "bsp_f723_disco/pmod/pmod.h"

#include "cli/cli_server.h"
#include "cli/shell/cli_shell.h"


void MX_GPIO_Init();




int main()
{
	const char* version = GIT_DESCRIBE;

	HAL_Init();
	mcu::initSystemClock();
	HAL_Delay(500);
	mcu::gpio::enableClocks();

	MX_GPIO_Init();

	/* BSP */
	bsp::initLedRed();
	bsp::initLedGreen();
	bsp::initWakeupButton();
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
					.advanced = {.AdvFeatureInit = UART_ADVFEATURE_NO_INIT}};
	mcu::uart::Uart<7> uart7(uart7RxPinCfg, uart7TxPinCfg, uart7Cfg);

	/* CLI */
	cli::Server cliServer("stm32-disco", &uart7, nullptr, nullptr);
	cli::Shell::init();
	cliServer.registerExecCallback(cli::Shell::exec);
	cli::nextline_blocking();
	cli::nextline_blocking();
	cli::nextline_blocking();
	cli::print_blocking(CLI_WELCOME_STRING);

	/* TEST */
	std::stringstream sstr;
	sstr << "red: " << bsp::ledRed.no() << "; green: " << bsp::ledGreen.no();
	bsp::LCD_st7789h2::instance().print(1, sstr.str().c_str());
	
	bsp::wakeupButton.initInterrupt(bsp::onWakeupButtonInterrupt, mcu::InterruptPriority(2));
	bsp::wakeupButton.enableInterrupts();

	while (1)
	{
		cliServer.run();
	}
}




void bsp::onWakeupButtonInterrupt()
{
	bsp::LCD_st7789h2::instance().clearLine(2);
	if (bsp::wakeupButton.read() == emb::PinState::ACTIVE)
	{
		bsp::LCD_st7789h2::instance().print(2, "pressed");
	}
	else
	{
		bsp::LCD_st7789h2::instance().print(2, "released");
	}
}
