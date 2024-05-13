cmake_minimum_required(VERSION 3.15)

project(BSP)

add_library(BSP 
        led.c
        btimer.c
        ps2.c
        lcd.c
        st7789.c)

target_include_directories(BSP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} 
        pico_stdlib
        hardware_adc
        hardware_spi
        hardware_dma
        hardware_pwm)

