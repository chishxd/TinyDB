cmake_minimum_required(VERSION 3.10)
project(TinyDB C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(TinyDB
        src/main.c
        src/student.c
        src/utils.c
)

# Rename output binary
set_target_properties(TinyDB PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        OUTPUT_NAME "tinydb"
)
