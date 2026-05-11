cmake_minimum_required(VERSION 3.10)
project(CSnake)

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

include_directories(include/)

add_executable(C_SNAKE ${SOURCES})

set_target_properties(C_SNAKE PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

target_compile_options(C_SNAKE PRIVATE 
    "-Wall" 
    "-fdiagnostics-color=always"
    "-g"
)