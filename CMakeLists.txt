# Generated Cmake Pico project file
cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "D:/Pico_env/pico-sdk")
set(PICO_BOARD pico CACHE STRING "Board type")
# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()
project(main C CXX ASM)
# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()
# Add executable. Default name is the project name, version 0.1
add_executable(main main.c )
pico_set_program_name(main "main")
pico_set_program_version(main "0.1")
pico_enable_stdio_uart(main 1)
pico_enable_stdio_usb(main 0)
# Add the standard include files to the build
target_include_directories(main PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

set(FREERTOS_KERNEL_PATH "FreeRTOS-Kernel")
# Add the freertos_config for FreeRTOS-Kernel
add_library(freertos_config INTERFACE)
target_include_directories(freertos_config SYSTEM
        INTERFACE
        "./"
)
# Select the heap port.  values between 1-4 will pick a heap.
set(FREERTOS_HEAP "4" CACHE STRING "" FORCE)
# Select the native compile PORT
set(FREERTOS_PORT "GCC_RP2040" CACHE STRING "" FORCE)
# Adding the FreeRTOS-Kernel subdirectory
add_subdirectory(${FREERTOS_KERNEL_PATH} FreeRTOS-Kernel)
# Add any user requested libraries
target_link_libraries(${PROJECT_NAME} 
        pico_stdlib
        hardware_spi
        pico_multicore
        freertos_kernel 
        freertos_config)

pico_add_extra_outputs(main)

add_subdirectory(BSP)
target_link_libraries(${PROJECT_NAME} BSP)