/**
 * @file lcd_st7789h2.h
 * @author Oleg Aushev (aushevom@protonmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once


#include "stm32f723e_discovery_lcd.h"
#include "mcu_stm32f7/system/mcu_system.h"
#include <cstring>
#include <cassert>


namespace bsp {


class LCD_st7789h2
{
private:
	LCD_st7789h2(sFONT* font);
	LCD_st7789h2(const LCD_st7789h2& other) = delete;
	LCD_st7789h2& operator=(const LCD_st7789h2& other) = delete;

	static LCD_st7789h2& instance_impl(sFONT* font = nullptr)
	{
		static LCD_st7789h2 s_instance(font);
		return s_instance;
	}

public:
	static void init(sFONT* font)
	{
		instance_impl(font);
	}

	static LCD_st7789h2& instance()
	{
		return instance_impl();
	}

	void print(uint16_t line, const char* str)
	{
		char buf[32];
		strncpy(buf, str, 32);
		BSP_LCD_DisplayStringAtLine(line, reinterpret_cast<uint8_t*>(buf));
	}

	void clearLine(uint16_t line)
	{
		BSP_LCD_ClearStringLine(line);
	}

};


} // namespace bsp



