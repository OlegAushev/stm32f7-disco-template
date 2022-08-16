# STM32 Minimal CMake project for C/C++ projects
cmake_minimum_required(VERSION 3.12)
include(gcc-arm-none-eabi.cmake)

################################################################################
project(disco-f7 VERSION 0.1)

# Set microcontroller information
set(MCU_DEVBOARD STM32F723E-Discovery)
set(MCU_FAMILY STM32F7xx)
set(MCU_MODEL STM32F723xx)
set(CPU_PARAMETERS
	-mcpu=cortex-m7
	-mthumb
	-mfpu=fpv5-sp-d16
	-mfloat-abi=hard)

set(MCU_STARTUP_SCRIPT ${PROJECT_SOURCE_DIR}/src/startup_stm32f723xx.s)
set(MCU_LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/STM32F723IEKx_FLASH.ld)
################################################################################

set(EXECUTABLE ${CMAKE_PROJECT_NAME})
enable_language(C CXX ASM)

################################################################################
# Set headers and sources
set(STM32CUBEMX_INCLUDE_DIRECTORIES
	${PROJECT_SOURCE_DIR}/drivers/${MCU_FAMILY}_HAL_Driver
	${PROJECT_SOURCE_DIR}/drivers/${MCU_FAMILY}_HAL_Driver/Inc
	${PROJECT_SOURCE_DIR}/drivers/${MCU_FAMILY}_HAL_Driver/Inc/Legacy
	${PROJECT_SOURCE_DIR}/drivers/CMSIS/Device/ST/${MCU_FAMILY}/Include
	${PROJECT_SOURCE_DIR}/drivers/CMSIS/Include
	${PROJECT_SOURCE_DIR}/BSP/Components
	${PROJECT_SOURCE_DIR}/BSP/${MCU_DEVBOARD}
)

set(PROJECT_INCLUDE_DIRECTORIES
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
)

file(GLOB_RECURSE STM32CUBEMX_SOURCES CONFIGURE_DEPENDS
	${PROJECT_SOURCE_DIR}/drivers/${MCU_FAMILY}_HAL_Driver/*.c
)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
	${PROJECT_SOURCE_DIR}/include/*.c
	${PROJECT_SOURCE_DIR}/include/*.cpp
	${PROJECT_SOURCE_DIR}/src/*.c
	${PROJECT_SOURCE_DIR}/src/*.cpp
)

################################################################################
# Set executable
add_executable(${EXECUTABLE}
	${STM32CUBEMX_SOURCES}
	${PROJECT_SOURCES}
	${MCU_STARTUP_SCRIPT}
)

target_compile_definitions(${EXECUTABLE} PRIVATE
	$<$<CONFIG:Debug>:DEBUG>
	${MCU_MODEL}
	USE_HAL_DRIVER
)

target_include_directories(${EXECUTABLE} SYSTEM PRIVATE
	${STM32CUBEMX_INCLUDE_DIRECTORIES}
)

target_include_directories(${EXECUTABLE} PRIVATE
	${PROJECT_INCLUDE_DIRECTORIES}
)

################################################################################
# Set compiler options and features
target_compile_options(${EXECUTABLE} PRIVATE
	${CPU_PARAMETERS}
	-Wall
	-Wextra
	-Wpedantic
	-Wshadow
	-Wdouble-promotion
	-Wformat=2 -Wformat-truncation
	-Wundef
	-fno-common
	-Wno-unused-parameter
	$<$<COMPILE_LANGUAGE:CXX>:
		-Wconversion
		-Wno-volatile
		-Wold-style-cast
		-Wuseless-cast
		-Wsuggest-override>
	$<$<CONFIG:Debug>:-Og -g3 -ggdb>
	$<$<CONFIG:Release>:-Og -g0>
)

################################################################################
# Set linker options
target_link_options(${EXECUTABLE} PRIVATE
	-T${MCU_LINKER_SCRIPT}
	${CPU_PARAMETERS}
	-Wl,-Map=${CMAKE_PROJECT_NAME}.map
	--specs=nosys.specs
	-Wl,--start-group
	-lc
	-lm
	-lstdc++
	-Wl,--end-group
	-Wl,--print-memory-usage
)

target_compile_features(${EXECUTABLE} PRIVATE
	c_std_11
	cxx_std_17
)

################################################################################
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
	COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>
	COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.hex
	COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}> ${EXECUTABLE}.bin
)

if (${DUMP_ASM})
	add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
		COMMAND ${CMAKE_OBJDUMP} -D $<TARGET_FILE:${EXECUTABLE}> > ${EXECUTABLE}.s)
endif()


