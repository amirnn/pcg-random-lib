cmake_minimum_required(VERSION 3.29.0)
project(pcg-random-lib VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(EXPORT_COMPILE_COMMANDS ON)

# library name
set(LIBRARY_NAME pcg-random-lib)
add_library(${LIBRARY_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/pcg-random-lib.hpp")
target_include_directories(
        ${LIBRARY_NAME} INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/libs/pcg-cpp/include"
)

if (MSVC)
    target_compile_options(${LIBRARY_NAME} PRIVATE /W4 /WX)
else ()
    target_compile_options(${LIBRARY_NAME} INTERFACE -Wall -Wextra -Wpedantic -Werror)
endif ()

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

