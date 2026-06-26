project(UnitTests VERSION 0.1.0 LANGUAGES CXX)
message(STATUS "SubProject ${PROJECT_NAME}")

find_path(CPPUTEST_INCLUDE_DIR
    NAMES CppUTest/TestHarness.h
    REQUIRED
)

find_library(CPPUTEST_LIBRARY
    NAMES CppUTest
    REQUIRED
)

find_library(CPPUTEST_EXT_LIBRARY
    NAMES CppUTestExt
    REQUIRED
)


# Gather all source files from the tests directory
file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Create an executable for tests
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CPPUTEST_INCLUDE_DIR}
)

if(NOT MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE -fexceptions)
endif()

find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CPPUTEST_LIBRARY}
    ${CPPUTEST_EXT_LIBRARY}
    Threads::Threads
)