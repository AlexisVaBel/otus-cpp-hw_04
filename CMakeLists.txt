cmake_minimum_required(VERSION 3.5)

project(print_ip)
include_directories(".")
add_executable(print_ip main.cpp)

set_target_properties(print_ip PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )
