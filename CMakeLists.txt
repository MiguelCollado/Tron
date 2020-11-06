cmake_minimum_required(VERSION 3.16)
project(TronEngine)

add_compile_definitions(TN_PLATFORM_WINDOWS)

add_subdirectory(Tron)
add_subdirectory(Sandbox)