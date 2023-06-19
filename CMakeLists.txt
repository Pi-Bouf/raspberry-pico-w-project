cmake_minimum_required(VERSION 3.12)

include_directories(pico-sdk)
include_directories(pimoroni-pico)

add_subdirectory(pimoroni-pico)

project(pico_examples C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include_directories(
  ${CMAKE_CURRENT_LIST_DIR}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(OUTPUT_NAME pico_big_room_project)

add_executable(
  ${OUTPUT_NAME}
  main.cpp
)

# Pull in pico libraries that we need
target_link_libraries(${OUTPUT_NAME} pico_stdlib hardware_spi hardware_pwm hardware_dma rgbled button pico_display_2 st7789 pico_graphics)

pico_enable_stdio_usb(pico_big_room_project 1) 
pico_enable_stdio_uart(pico_big_room_project 0) 

# create map/bin/hex file etc.
pico_add_extra_outputs(${OUTPUT_NAME})