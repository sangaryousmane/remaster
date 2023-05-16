cmake_minimum_required(VERSION 3.24)
project(remaster)

set(CMAKE_CXX_STANDARD 17)

add_executable(remaster main.c remaster/structs/animal.c  remaster/linkedlist/tasks.c remaster/linkedlist/LinkedList.c remaster/linkedlist/linkedlist2.c remaster/structs/Car.c remaster/structs/tasks.c remaster/structs/House.c remaster/structs/airplane.c remaster/bit-manipulation/tasks.c remaster/file-handling/handle.c remaster/file-handling/tasks.c remaster/file-handling/main.h remaster/file-handling/elf_file.c remaster/shell/random.c remaster/recursion/basics.c remaster/recursion/basics.c)
