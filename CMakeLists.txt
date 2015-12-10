cmake_minimum_required(VERSION 3.3)
project(parser)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -ansi -pedantic -std=c99 -static-libgcc -static-libstdc++")

set(SOURCE_FILES main.c parser/parser.c parser/parser.h parser/scanner.c parser/scanner.h)
add_executable(parser ${SOURCE_FILES})