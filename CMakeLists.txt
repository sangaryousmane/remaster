cmake_minimum_required(VERSION 3.24)
project(remaster)

set(CMAKE_CXX_STANDARD 17)

add_executable(remaster main.c remaster/structs/animal.c)
