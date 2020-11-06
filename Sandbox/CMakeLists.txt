cmake_minimum_required(VERSION 3.16)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

include_directories(../Tron/vendor/spdlog/include)
include_directories(../Tron/vendor/Glad/include)
include_directories(../Tron/vendor/GLFW/include)
include_directories(../Tron/vendor/imgui)
include_directories(../Tron/vendor/stb_image)
include_directories(../Tron/vendor/glm)

include_directories(../Tron/src)

set(SOURCES
        src/SandboxApp.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Tron)