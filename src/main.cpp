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
#include "mcu_stm32f7/can/mcu_can.h"

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
	HAL_Init();
	mcu::initDeviceClock();
	HAL_Delay(500);
	mcu::gpio::enableClocks();

	MX_GPIO_Init();

	/* UART */
	bsp::initPmod(bsp::PmodConfiguration::UART);
	mcu::uart::RxPinConfig uart7RxPinConfig = {.port = PMOD3_RX_PORT, .pin = PMOD3_RX_PIN, .afSelection = GPIO_AF8_UART7};
	mcu::uart::TxPinConfig uart7TxPinConfig = {.port = PMOD2_TX_PORT, .pin = PMOD2_TX_PIN, .afSelection = GPIO_AF8_UART7};
	mcu::uart::Config uart7Config = {.init = {	
						.BaudRate = 9600,
						.WordLength = UART_WORDLENGTH_8B,
						.StopBits = UART_STOPBITS_1,
						.Parity = UART_PARITY_NONE,
						.Mode = UART_MODE_TX_RX,
						.HwFlowCtl = UART_HWCONTROL_NONE},
					.advanced = {
						.AdvFeatureInit = UART_ADVFEATURE_NO_INIT}};
	mcu::uart::Uart<7> uart7(uart7RxPinConfig, uart7TxPinConfig, uart7Config);

	/* CLI */
	cli::Server cliServer("stm32-disco", &uart7, nullptr, nullptr);
	cli::Shell::init();
	cliServer.registerExecCallback(cli::Shell::exec);
	cli::nextline_blocking();
	cli::nextline_blocking();
	cli::nextline_blocking();
	cli::print_blocking(CLI_WELCOME_STRING);
	cli::nextline_blocking();
	cli::print_blocking(CLI_COLOR_YELLOW);
	cli::print_blocking("stm32f7-disco-template | ");
	cli::print_blocking(GIT_DESCRIBE);
	cli::print_blocking(CLI_COLOR_OFF);

	/* BSP */
	cli::nextline_blocking();
	cli::print_blocking("initialize bsp... ");

	bsp::initLedRed();
	bsp::initLedGreen();
	bsp::initButtonWakeup();

	cli::print_blocking("done");
	
	/* LCD */
	cli::nextline_blocking();
	cli::print_blocking("initialize lcd... ");

	bsp::LCD_st7789h2::init();
	bsp::LCD_st7789h2::instance().setFont(bsp::FontSize::HEIGHT_16, bsp::LcdColor::GRAY, bsp::LcdColor::BLACK);
	bsp::LCD_st7789h2::instance().print(0, GIT_DESCRIBE);

	cli::print_blocking("done");

	/* CLOCK */
	cli::nextline_blocking();
	cli::print_blocking("configure system clock... ");

	mcu::SystemClock::init();

	cli::print_blocking("done");

	/* CAN */
	cli::nextline_blocking();
	cli::print_blocking("configure CAN1 module...");

	mcu::can::RxPinConfig can1RxPinConfig = {.port = STMOD_CAN_RX_PORT, .pin = STMOD_CAN_RX_PIN, .afSelection = GPIO_AF9_CAN1};
	mcu::can::TxPinConfig can1TxPinConfig = {.port = STMOD_CAN_TX_PORT, .pin = STMOD_CAN_TX_PIN, .afSelection = GPIO_AF9_CAN1};
	mcu::can::Config can1Config = {.init = {
						.Prescaler = 25,
						.Mode = CAN_MODE_NORMAL,
						.SyncJumpWidth = CAN_SJW_1TQ,
						.TimeSeg1 = CAN_BS1_13TQ,
						.TimeSeg2 = CAN_BS2_2TQ,
						.TimeTriggeredMode = DISABLE,
						.AutoBusOff = DISABLE,
						.AutoWakeUp = DISABLE,
						.AutoRetransmission = ENABLE,
						.ReceiveFifoLocked = DISABLE,
						.TransmitFifoPriority = DISABLE}};
	mcu::can::Can<1>(can1RxPinConfig, can1TxPinConfig, can1Config);

	cli::print_blocking("done");

	/* TEST */
	bsp::buttonWakeup.initInterrupt(bsp::onButtonWakeupInterrupt, mcu::InterruptPriority(2));
	bsp::buttonWakeup.enableInterrupts();
	bsp::LCD_st7789h2::instance().print(4, "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_");
	bsp::LCD_st7789h2::instance().print(5, -3.1416f);
	bsp::LCD_st7789h2::instance().print(6, -101);
	bsp::LCD_st7789h2::instance().print(7, uint64_t(42));

	cli::nextline_blocking();
	cli::print_blocking("device is ready!");

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
	bsp::ledRed.set();
}


