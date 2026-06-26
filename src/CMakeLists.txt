project(App LANGUAGES CXX)
message(STATUS "Subproject ${PROJECT_NAME}")

# Generate app_config.hpp from app_config.hpp.in
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/app_config.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/app_config.hpp
    @ONLY
)

# Main application executable
add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_BINARY_DIR}
)