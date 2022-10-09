#include "stm32f7xx_hal.h"


#define ARD_D7_GPIO_Pin GPIO_PIN_3
#define ARD_D7_GPIO_GPIO_Port GPIOE
#define QSPI_D2_Pin GPIO_PIN_2
#define QSPI_D2_GPIO_Port GPIOE
#define PSRAM_NBL1_Pin GPIO_PIN_1
#define PSRAM_NBL1_GPIO_Port GPIOE
#define PSRAM_NBL0_Pin GPIO_PIN_0
#define PSRAM_NBL0_GPIO_Port GPIOE
#define SAI2_I2C1_SCL_Pin GPIO_PIN_8
#define SAI2_I2C1_SCL_GPIO_Port GPIOB
#define ARD_D11_TIM3_CH2_SPI1_MOSI_Pin GPIO_PIN_5
#define ARD_D11_TIM3_CH2_SPI1_MOSI_GPIO_Port GPIOB
#define WIFI_RST_Pin GPIO_PIN_14
#define WIFI_RST_GPIO_Port GPIOG
#define WIFI_GPIO_0_Pin GPIO_PIN_13
#define WIFI_GPIO_0_GPIO_Port GPIOG
#define ARD_D12_SPI1_MISO_Pin GPIO_PIN_4
#define ARD_D12_SPI1_MISO_GPIO_Port GPIOB
#define SYS_STLINK_JTDO_SWO_Pin GPIO_PIN_3
#define SYS_STLINK_JTDO_SWO_GPIO_Port GPIOB
#define PSRAM_NE1_Pin GPIO_PIN_7
#define PSRAM_NE1_GPIO_Port GPIOD
#define UART_TXD_WIFI_RX_Pin GPIO_PIN_12
#define UART_TXD_WIFI_RX_GPIO_Port GPIOC
#define STMOD__TIM2_CH1_2_ETR_Pin GPIO_PIN_15
#define STMOD__TIM2_CH1_2_ETR_GPIO_Port GPIOA
#define ARD_D8_GPIO_Pin GPIO_PIN_4
#define ARD_D8_GPIO_GPIO_Port GPIOE
#define ARD_D3_TIM9_CH1_Pin GPIO_PIN_5
#define ARD_D3_TIM9_CH1_GPIO_Port GPIOE
#define ARD_D6_TIM9_CH2_Pin GPIO_PIN_6
#define ARD_D6_TIM9_CH2_GPIO_Port GPIOE
#define SAI2_I2C1_SDA_Pin GPIO_PIN_9
#define SAI2_I2C1_SDA_GPIO_Port GPIOB
#define NC1_Pin GPIO_PIN_7
#define NC1_GPIO_Port GPIOB
#define QSPI_NCS_Pin GPIO_PIN_6
#define QSPI_NCS_GPIO_Port GPIOB
#define SAI2_INT_Pin GPIO_PIN_15
#define SAI2_INT_GPIO_Port GPIOG
#define PMOD_GPIO_0_Pin GPIO_PIN_12
#define PMOD_GPIO_0_GPIO_Port GPIOG
#define SAI2_SD_B_Pin GPIO_PIN_10
#define SAI2_SD_B_GPIO_Port GPIOG
#define WIFI_GPIO_2_Pin GPIO_PIN_6
#define WIFI_GPIO_2_GPIO_Port GPIOD
#define LCD_PSRAM_D2_Pin GPIO_PIN_0
#define LCD_PSRAM_D2_GPIO_Port GPIOD
#define STMOD_UART4_RXD_s_Pin GPIO_PIN_11
#define STMOD_UART4_RXD_s_GPIO_Port GPIOC
#define QSPI_D1_Pin GPIO_PIN_10
#define QSPI_D1_GPIO_Port GPIOC
#define SAI2_FS_A_Pin GPIO_PIN_7
#define SAI2_FS_A_GPIO_Port GPIOI
#define SAI2_SD_A_Pin GPIO_PIN_6
#define SAI2_SD_A_GPIO_Port GPIOI
#define SAI2_SCK_A_Pin GPIO_PIN_5
#define SAI2_SCK_A_GPIO_Port GPIOI
#define LCD_NE_Pin GPIO_PIN_9
#define LCD_NE_GPIO_Port GPIOG
#define LCD_PSRAM_NWE_Pin GPIO_PIN_5
#define LCD_PSRAM_NWE_GPIO_Port GPIOD
#define LCD_PSRAM_D3_Pin GPIO_PIN_1
#define LCD_PSRAM_D3_GPIO_Port GPIOD
#define LOG_PI3_Pin GPIO_PIN_3
#define LOG_PI3_GPIO_Port GPIOI
#define LOG_PI2_Pin GPIO_PIN_2
#define LOG_PI2_GPIO_Port GPIOI
#define CTP_INT_Pin GPIO_PIN_9
#define CTP_INT_GPIO_Port GPIOI
#define SAI2_MCLK_A_Pin GPIO_PIN_4
#define SAI2_MCLK_A_GPIO_Port GPIOI
#define LCD_PSRAM_NWED4_Pin GPIO_PIN_4
#define LCD_PSRAM_NWED4_GPIO_Port GPIOD
#define WIFI_CH_PD_Pin GPIO_PIN_3
#define WIFI_CH_PD_GPIO_Port GPIOD
#define UART_RXD_WIFI_TX_Pin GPIO_PIN_2
#define UART_RXD_WIFI_TX_GPIO_Port GPIOD
#define PMOD_SEL_0_Pin GPIO_PIN_15
#define PMOD_SEL_0_GPIO_Port GPIOH
#define LOG_PI1_Pin GPIO_PIN_1
#define LOG_PI1_GPIO_Port GPIOI
#define USB_OTG_FS_ID_Pin GPIO_PIN_10
#define USB_OTG_FS_ID_GPIO_Port GPIOA
#define PSRAM_A0_Pin GPIO_PIN_0
#define PSRAM_A0_GPIO_Port GPIOF
#define PMOD_SEL_1_Pin GPIO_PIN_10
#define PMOD_SEL_1_GPIO_Port GPIOI
#define LOG_PI0_Pin GPIO_PIN_0
#define LOG_PI0_GPIO_Port GPIOI
#define PMOD_GPIO_1_Pin GPIO_PIN_2
#define PMOD_GPIO_1_GPIO_Port GPIOH
#define QSPI_D0_Pin GPIO_PIN_9
#define QSPI_D0_GPIO_Port GPIOC
#define CTP_SCL_Pin GPIO_PIN_8
#define CTP_SCL_GPIO_Port GPIOA
#define ARD_D4_GPIO_Pin GPIO_PIN_3
#define ARD_D4_GPIO_GPIO_Port GPIOH
#define LCD_TE_INT_Pin GPIO_PIN_8
#define LCD_TE_INT_GPIO_Port GPIOC
#define VCP_RX_Pin GPIO_PIN_7
#define VCP_RX_GPIO_Port GPIOC
#define PSRAM_A2_Pin GPIO_PIN_2
#define PSRAM_A2_GPIO_Port GPIOF
#define PSRAM_A1_Pin GPIO_PIN_1
#define PSRAM_A1_GPIO_Port GPIOF
#define ARD_D15_STMOD_I2C2_SCL_Pin GPIO_PIN_4
#define ARD_D15_STMOD_I2C2_SCL_GPIO_Port GPIOH
#define USB_OTGFS_PPWR_EN_Pin GPIO_PIN_8
#define USB_OTGFS_PPWR_EN_GPIO_Port GPIOG
#define VCP_TX_Pin GPIO_PIN_6
#define VCP_TX_GPIO_Port GPIOC
#define PSRAM_A3_Pin GPIO_PIN_3
#define PSRAM_A3_GPIO_Port GPIOF
#define PSRAM_A4_Pin GPIO_PIN_4
#define PSRAM_A4_GPIO_Port GPIOF
#define ARD_D14_STMOD_I2C2_SDA_Pin GPIO_PIN_5
#define ARD_D14_STMOD_I2C2_SDA_GPIO_Port GPIOH
#define PMOD_UART7_TXD_Pin GPIO_PIN_7
#define PMOD_UART7_TXD_GPIO_Port GPIOF
#define PMOD_UART7_RXD_Pin GPIO_PIN_6
#define PMOD_UART7_RXD_GPIO_Port GPIOF
#define PSRAM_A5_Pin GPIO_PIN_5
#define PSRAM_A5_GPIO_Port GPIOF
#define USB_OTGHS_PPWR_EN_Pin GPIO_PIN_12
#define USB_OTGHS_PPWR_EN_GPIO_Port GPIOH
#define PSRAM_A15_Pin GPIO_PIN_5
#define PSRAM_A15_GPIO_Port GPIOG
#define PSRAM_A14_Pin GPIO_PIN_4
#define PSRAM_A14_GPIO_Port GPIOG
#define PSRAM_A13_Pin GPIO_PIN_3
#define PSRAM_A13_GPIO_Port GPIOG
#define ARD_A3_ADC3_IN8_Pin GPIO_PIN_10
#define ARD_A3_ADC3_IN8_GPIO_Port GPIOF
#define PMOD_UART7_CTS_Pin GPIO_PIN_9
#define PMOD_UART7_CTS_GPIO_Port GPIOF
#define PMOD_UART7_RTS_Pin GPIO_PIN_8
#define PMOD_UART7_RTS_GPIO_Port GPIOF
#define LCD_BL_Pin GPIO_PIN_11
#define LCD_BL_GPIO_Port GPIOH
#define USB_OTGHS_OVCR_INT_Pin GPIO_PIN_10
#define USB_OTGHS_OVCR_INT_GPIO_Port GPIOH
#define LCD_PSRAM_D1_Pin GPIO_PIN_15
#define LCD_PSRAM_D1_GPIO_Port GPIOD
#define PSRAM_A12_Pin GPIO_PIN_2
#define PSRAM_A12_GPIO_Port GPIOG
#define ARD_A4_Pin GPIO_PIN_0
#define ARD_A4_GPIO_Port GPIOC
#define ARD_A5_Pin GPIO_PIN_1
#define ARD_A5_GPIO_Port GPIOC
#define STMOD_SPI2_MISOs_Pin GPIO_PIN_2
#define STMOD_SPI2_MISOs_GPIO_Port GPIOC
#define STMOD__SPI2_MOSIs_Pin GPIO_PIN_3
#define STMOD__SPI2_MOSIs_GPIO_Port GPIOC
#define QSPI_CLK_Pin GPIO_PIN_2
#define QSPI_CLK_GPIO_Port GPIOB
#define PSRAM_A11_Pin GPIO_PIN_1
#define PSRAM_A11_GPIO_Port GPIOG
#define ARD_D9_TIM12_CH1_Pin GPIO_PIN_6
#define ARD_D9_TIM12_CH1_GPIO_Port GPIOH
#define CTP_SDA_Pin GPIO_PIN_8
#define CTP_SDA_GPIO_Port GPIOH
#define CTP_RST_Pin GPIO_PIN_9
#define CTP_RST_GPIO_Port GPIOH
#define LCD_PSRAM_D0_Pin GPIO_PIN_14
#define LCD_PSRAM_D0_GPIO_Port GPIOD
#define QSPI_D3_Pin GPIO_PIN_13
#define QSPI_D3_GPIO_Port GPIOD
#define ARD_D10_TIM2_CH2_SPI1_NSS_Pin GPIO_PIN_1
#define ARD_D10_TIM2_CH2_SPI1_NSS_GPIO_Port GPIOA
#define SYS_B_User_Pin GPIO_PIN_0
#define SYS_B_User_GPIO_Port GPIOA
#define ARD_A1_Pin GPIO_PIN_4
#define ARD_A1_GPIO_Port GPIOA
#define ARD_A2_Pin GPIO_PIN_4
#define ARD_A2_GPIO_Port GPIOC
#define PSRAM_A7_Pin GPIO_PIN_13
#define PSRAM_A7_GPIO_Port GPIOF
#define PSRAM_A10_Pin GPIO_PIN_0
#define PSRAM_A10_GPIO_Port GPIOG
#define LCD_PSRAM_D10_Pin GPIO_PIN_13
#define LCD_PSRAM_D10_GPIO_Port GPIOE
#define LCD_RST_Pin GPIO_PIN_7
#define LCD_RST_GPIO_Port GPIOH
#define PSRAM_A17_Pin GPIO_PIN_12
#define PSRAM_A17_GPIO_Port GPIOD
#define PSRAM_A16_Pin GPIO_PIN_11
#define PSRAM_A16_GPIO_Port GPIOD
#define LCD_PSRAM_D15_Pin GPIO_PIN_10
#define LCD_PSRAM_D15_GPIO_Port GPIOD
#define ARD_D1_USART2_TX_Pin GPIO_PIN_2
#define ARD_D1_USART2_TX_GPIO_Port GPIOA
#define ARD_A0_Pin GPIO_PIN_6
#define ARD_A0_GPIO_Port GPIOA
#define ARD_D2_GPIO_Pin GPIO_PIN_5
#define ARD_D2_GPIO_GPIO_Port GPIOC
#define PSRAM_A6_Pin GPIO_PIN_12
#define PSRAM_A6_GPIO_Port GPIOF
#define PSRAM_A9_Pin GPIO_PIN_15
#define PSRAM_A9_GPIO_Port GPIOF
#define LCD_PSRAM_D5_Pin GPIO_PIN_8
#define LCD_PSRAM_D5_GPIO_Port GPIOE
#define LCD_PSRAM_D6_Pin GPIO_PIN_9
#define LCD_PSRAM_D6_GPIO_Port GPIOE
#define LCD_PSRAM_D8_Pin GPIO_PIN_11
#define LCD_PSRAM_D8_GPIO_Port GPIOE
#define LCD_PSRAM_D11_Pin GPIO_PIN_14
#define LCD_PSRAM_D11_GPIO_Port GPIOE
#define USB_OTG_HS_ID_Pin GPIO_PIN_12
#define USB_OTG_HS_ID_GPIO_Port GPIOB
#define USB_OTG_HS_VBUS_Pin GPIO_PIN_13
#define USB_OTG_HS_VBUS_GPIO_Port GPIOB
#define LCD_PSRAM_D14_Pin GPIO_PIN_9
#define LCD_PSRAM_D14_GPIO_Port GPIOD
#define LCD_PSRAM_D13_Pin GPIO_PIN_8
#define LCD_PSRAM_D13_GPIO_Port GPIOD
#define ARD_D0_USART2_RX_Pin GPIO_PIN_3
#define ARD_D0_USART2_RX_GPIO_Port GPIOA
#define ARD_D5_STMOD_TIM3_CH3_Pin GPIO_PIN_0
#define ARD_D5_STMOD_TIM3_CH3_GPIO_Port GPIOB
#define PMOD_RESET_Pin GPIO_PIN_11
#define PMOD_RESET_GPIO_Port GPIOF
#define PSRAM_A8_Pin GPIO_PIN_14
#define PSRAM_A8_GPIO_Port GPIOF
#define LCD_PSRAM_D4_Pin GPIO_PIN_7
#define LCD_PSRAM_D4_GPIO_Port GPIOE
#define LCD_PSRAM_D7_Pin GPIO_PIN_10
#define LCD_PSRAM_D7_GPIO_Port GPIOE
#define LCD_PSRAM_D9_Pin GPIO_PIN_12
#define LCD_PSRAM_D9_GPIO_Port GPIOE
#define LCD_PSRAM_D12_Pin GPIO_PIN_15
#define LCD_PSRAM_D12_GPIO_Port GPIOE
#define USB_OTGFS_OVCR_INT_Pin GPIO_PIN_10
#define USB_OTGFS_OVCR_INT_GPIO_Port GPIOB
#define PMOD_INT_Pin GPIO_PIN_11
#define PMOD_INT_GPIO_Port GPIOB

















void MX_GPIO_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct = {};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOE, ARD_D7_GPIO_Pin|ARD_D8_GPIO_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOG, WIFI_RST_Pin|WIFI_GPIO_0_Pin|PMOD_GPIO_0_Pin|USB_OTGFS_PPWR_EN_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD, WIFI_GPIO_2_Pin|WIFI_CH_PD_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, STMOD_UART4_RXD_s_Pin|ARD_D2_GPIO_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOI, LOG_PI3_Pin|LOG_PI2_Pin|LOG_PI1_Pin|PMOD_SEL_1_Pin
				|LOG_PI0_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOH, PMOD_SEL_0_Pin|PMOD_GPIO_1_Pin|ARD_D4_GPIO_Pin|USB_OTGHS_PPWR_EN_Pin
				|CTP_RST_Pin|LCD_RST_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, USB_OTG_FS_ID_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, USB_OTG_HS_ID_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : PEPin PEPin */
	GPIO_InitStruct.Pin = ARD_D7_GPIO_Pin|ARD_D8_GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pins : PBPin PBPin */
	GPIO_InitStruct.Pin = ARD_D11_TIM3_CH2_SPI1_MOSI_Pin|ARD_D12_SPI1_MISO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : PGPin PGPin PGPin PGPin */
	GPIO_InitStruct.Pin = WIFI_RST_Pin|WIFI_GPIO_0_Pin|PMOD_GPIO_0_Pin|USB_OTGFS_PPWR_EN_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = SAI2_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(SAI2_INT_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : PDPin PDPin */
	GPIO_InitStruct.Pin = WIFI_GPIO_2_Pin|WIFI_CH_PD_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pins : PCPin PCPin */
	GPIO_InitStruct.Pin = STMOD_UART4_RXD_s_Pin|ARD_D2_GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : PIPin PIPin PIPin PIPin */
	GPIO_InitStruct.Pin = LOG_PI3_Pin|LOG_PI2_Pin|LOG_PI1_Pin|LOG_PI0_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = CTP_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(CTP_INT_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : PHPin PHPin PHPin PHPin
				PHPin PHPin */
	GPIO_InitStruct.Pin = PMOD_SEL_0_Pin|PMOD_GPIO_1_Pin|ARD_D4_GPIO_Pin|USB_OTGHS_PPWR_EN_Pin
				|CTP_RST_Pin|LCD_RST_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

	/*Configure GPIO pins : PAPin PAPin PAPin */
	GPIO_InitStruct.Pin = USB_OTG_FS_ID_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = PMOD_SEL_1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(PMOD_SEL_1_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = LCD_TE_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(LCD_TE_INT_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = USB_OTGHS_OVCR_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(USB_OTGHS_OVCR_INT_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : PCPin PCPin */
	GPIO_InitStruct.Pin = STMOD_SPI2_MISOs_Pin|STMOD__SPI2_MOSIs_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : PBPin PBPin */
	GPIO_InitStruct.Pin = USB_OTG_HS_ID_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : PBPin PBPin PBPin */
	GPIO_InitStruct.Pin = USB_OTG_HS_VBUS_Pin|USB_OTGFS_OVCR_INT_Pin|PMOD_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = PMOD_RESET_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(PMOD_RESET_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : PB14 PB15 */
	GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF12_OTG_HS_FS;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}


