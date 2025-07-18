cmake_minimum_required(VERSION 3.10)
project(StudentManager C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(StudentManager
        src/main.c
        src/student.c
)
