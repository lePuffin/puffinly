# Example of how to use FetchContent to fetch and build an external library.

# cmake_minimum_required(VERSION 3.28)

# include(FetchContent)

# # Prevent reinstalling if already fetched
# set(FETCHCONTENT_QUIET OFF)

# FetchContent_Declare(
#     nlohmann_json
#     GIT_REPOSITORY https://github.com/nlohmann/json.git
#     GIT_TAG v3.12.0
# )

# FetchContent_MakeAvailable(nlohmann_json)
