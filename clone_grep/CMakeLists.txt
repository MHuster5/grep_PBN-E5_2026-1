cmake_minimum_required(VERSION 3.14)
project(clone_grep)

set(CMAKE_C_STANDARD 17)

# Ajusta source e include
include_directories(include)
add_executable(${PROJECT_NAME} src/main.c)
