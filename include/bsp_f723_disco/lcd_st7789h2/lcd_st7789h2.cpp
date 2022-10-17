/**
 * @file lcd_st7789h2.cpp
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "lcd_st7789h2.h"


namespace bsp {


void MX_FMC_Init();


///
///
///
LCD_st7789h2::LCD_st7789h2(sFONT* font)
{
	assert(font != nullptr);

	MX_FMC_Init();
	BSP_LCD_Init();
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(font);
}


SRAM_HandleTypeDef hsram1;
SRAM_HandleTypeDef hsram2;


/**
 * @brief Generated by CubeMX.
 * 
 */
void MX_FMC_Init(void)
{
	FMC_NORSRAM_TimingTypeDef Timing = {};

	/** Perform the SRAM1 memory initialization sequence
	 */
	hsram1.Instance = FMC_NORSRAM_DEVICE;
	hsram1.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
	/* hsram1.Init */
	hsram1.Init.NSBank = FMC_NORSRAM_BANK1;
	hsram1.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
	hsram1.Init.MemoryType = FMC_MEMORY_TYPE_PSRAM;
	hsram1.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16;
	hsram1.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
	hsram1.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
	hsram1.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
	hsram1.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
	hsram1.Init.WaitSignal = FMC_WAIT_SIGNAL_DISABLE;
	hsram1.Init.ExtendedMode = FMC_EXTENDED_MODE_DISABLE;
	hsram1.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
	hsram1.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
	hsram1.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
	hsram1.Init.WriteFifo = FMC_WRITE_FIFO_ENABLE;
	hsram1.Init.PageSize = FMC_PAGE_SIZE_NONE;
	/* Timing */
	Timing.AddressSetupTime = 15;
	Timing.AddressHoldTime = 15;
	Timing.DataSetupTime = 255;
	Timing.BusTurnAroundDuration = 15;
	Timing.CLKDivision = 16;
	Timing.DataLatency = 17;
	Timing.AccessMode = FMC_ACCESS_MODE_A;
	/* ExtTiming */

	if (HAL_SRAM_Init(&hsram1, &Timing, NULL) != HAL_OK)
	{
		mcu::fatal_error("SRAM1 initialization failed");
	}

	/** Perform the SRAM2 memory initialization sequence
	 */
	hsram2.Instance = FMC_NORSRAM_DEVICE;
	hsram2.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
	/* hsram2.Init */
	hsram2.Init.NSBank = FMC_NORSRAM_BANK2;
	hsram2.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
	hsram2.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
	hsram2.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16;
	hsram2.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
	hsram2.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
	hsram2.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
	hsram2.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
	hsram2.Init.WaitSignal = FMC_WAIT_SIGNAL_DISABLE;
	hsram2.Init.ExtendedMode = FMC_EXTENDED_MODE_DISABLE;
	hsram2.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
	hsram2.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
	hsram2.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
	hsram2.Init.WriteFifo = FMC_WRITE_FIFO_ENABLE;
	hsram2.Init.PageSize = FMC_PAGE_SIZE_NONE;
	/* Timing */
	Timing.AddressSetupTime = 15;
	Timing.AddressHoldTime = 15;
	Timing.DataSetupTime = 255;
	Timing.BusTurnAroundDuration = 15;
	Timing.CLKDivision = 16;
	Timing.DataLatency = 17;
	Timing.AccessMode = FMC_ACCESS_MODE_A;
	/* ExtTiming */

	if (HAL_SRAM_Init(&hsram2, &Timing, NULL) != HAL_OK)
	{
		mcu::fatal_error("SRAM2 initialization failed");
	}

}


} // namespace bsp


