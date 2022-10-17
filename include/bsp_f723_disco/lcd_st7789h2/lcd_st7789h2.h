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
#include <type_traits>


namespace bsp {


enum class FontSize
{
	HEIGHT_8,
	HEIGHT_12,
	HEIGHT_16,
	HEIGHT_20,
	HEIGHT_24	
};


enum class LcdColor : uint16_t
{
	BLUE = LCD_COLOR_BLUE,
	GREEN = LCD_COLOR_GREEN,
	RED = LCD_COLOR_RED,
	CYAN = LCD_COLOR_CYAN,
	MAGENTA = LCD_COLOR_MAGENTA,
	YELLOW = LCD_COLOR_YELLOW,
	LIGHTBLUE = LCD_COLOR_LIGHTBLUE,
	LIGHTGREEN = LCD_COLOR_LIGHTGREEN,
	LIGHTRED = LCD_COLOR_LIGHTRED,
	LIGHTMAGENTA = LCD_COLOR_LIGHTMAGENTA,
	LIGHTYELLOW = LCD_COLOR_LIGHTYELLOW,
	DARKBLUE = LCD_COLOR_DARKBLUE,
	DARKGREEN = LCD_COLOR_DARKGREEN,
	DARKRED = LCD_COLOR_DARKRED,
	DARKCYAN = LCD_COLOR_DARKCYAN,
	DARKMAGENTA = LCD_COLOR_DARKMAGENTA,
	DARKYELLOW = LCD_COLOR_DARKYELLOW,
	WHITE = LCD_COLOR_WHITE,
	LIGHTGRAY = LCD_COLOR_LIGHTGRAY,
	GRAY = LCD_COLOR_GRAY,
	DARKGRAY = LCD_COLOR_DARKGRAY,
	BLACK = LCD_COLOR_BLACK,
	BROWN = LCD_COLOR_BROWN,
	ORANGE = LCD_COLOR_ORANGE,
};


class LCD_st7789h2
{
private:
	LCD_st7789h2(FontSize fontSize);
public:
	LCD_st7789h2(const LCD_st7789h2& other) = delete;
	LCD_st7789h2& operator=(const LCD_st7789h2& other) = delete;
private:
	static LCD_st7789h2& instance_impl(FontSize fontSize = FontSize::HEIGHT_8)
	{
		static LCD_st7789h2 s_instance(fontSize);
		return s_instance;
	}

	size_t CHAR_IN_LINE_MAX_COUNT {0};

public:
	static void init(FontSize fontSize = FontSize::HEIGHT_8)
	{
		instance_impl(fontSize);
	}

	static LCD_st7789h2& instance()
	{
		return instance_impl();
	}

	void clearLine(uint16_t line)
	{
		BSP_LCD_ClearStringLine(line);
	}
	
	void clear(LcdColor color);


	void setFont(FontSize fontSize, LcdColor fontColor, LcdColor backColor);

	template <typename T>
	void print(uint16_t line, T t)
	{
		if constexpr (std::is_same<T, const char*>::value) { printChar(line, t); }
		else if constexpr (std::is_floating_point<T>::value) { printFloat(line, t); }
		else if constexpr (std::is_arithmetic<T>::value && std::is_signed<T>::value) { printInt(line, t); }
		else if constexpr (std::is_arithmetic<T>::value && !std::is_signed<T>::value) { printUint(line, t); }
		else { static_assert(std::is_same<T, const char*>::value
				|| std::is_floating_point<T>::value
				|| std::is_arithmetic<T>::value); }
	}

private:
	void printChar(uint16_t line, const char* str)
	{
		char buf[64] = {};
		strncpy(buf, str, CHAR_IN_LINE_MAX_COUNT);
		BSP_LCD_DisplayStringAtLine(line, reinterpret_cast<uint8_t*>(buf));
	}

	void printFloat(uint16_t line, double val)
	{
		char buf[64] = {};
		snprintf(buf, CHAR_IN_LINE_MAX_COUNT, "%.2f", val);
		BSP_LCD_DisplayStringAtLine(line, reinterpret_cast<uint8_t*>(buf));
	}
};


} // namespace bsp



