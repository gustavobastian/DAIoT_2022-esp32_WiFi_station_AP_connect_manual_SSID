# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)
set(COMPONENT_REQUIRES "json")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(sensor)


target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "main/client.crt" TEXT)
target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "main/client.key" TEXT)
target_add_binary_data(${CMAKE_PROJECT_NAME}.elf "main/broker_CA.crt" TEXT)
