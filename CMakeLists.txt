cmake_minimum_required(VERSION 3.28)

project(puffinly LANGUAGES CXX)
message(STATUS "Project ${PROJECT_NAME}")

set(VERSION 0.1.0)
set(PRODUCT_SHORT_NAME "puffinly")
set(PRODUCT_DESCRIPTION "A simple and direct library with safe types and validators.")
set(PRODUCT_MAINTAINER "lePuffin")

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Phase 1 lock: core library and consumer paths remain dependency-free.
option(PUFFINLY_BUILD_TESTS "Build CppUTest-based test target" ON)

# Avoids vscode red squiggles in main.cpp app_config.hpp inclusion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#---------------------------------------------------------------------------------------------------
# Add subdirectories
#---------------------------------------------------------------------------------------------------
add_subdirectory(src)

if(PUFFINLY_BUILD_TESTS)
	add_subdirectory(tests)
endif()