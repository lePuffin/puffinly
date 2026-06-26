cmake_minimum_required(VERSION 3.28)

project(BasicCPP LANGUAGES CXX)
message(STATUS "Project ${PROJECT_NAME}")

set(VERSION 0.1.0)
set(PRODUCT_SHORT_NAME "BasicCPP")
set(PRODUCT_DESCRIPTION "A simple C++ project template with CMake build system.")
set(PRODUCT_MAINTAINER "lePuffin")

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Avoids vscode red squiggles in main.cpp app_config.hpp inclusion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#---------------------------------------------------------------------------------------------------
# Add subdirectories
#---------------------------------------------------------------------------------------------------
add_subdirectory(src)
add_subdirectory(tests)