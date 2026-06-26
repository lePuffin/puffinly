project(App LANGUAGES CXX)
message(STATUS "Subproject ${PROJECT_NAME}")

# Generate app_config.hpp from app_config.hpp.in
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/app_config.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/app_config.hpp
    @ONLY
)

add_library(puffinly INTERFACE)
target_compile_features(puffinly INTERFACE cxx_std_17)
target_include_directories(puffinly INTERFACE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/libs
)

# Main application executable
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE puffinly)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_BINARY_DIR}
)