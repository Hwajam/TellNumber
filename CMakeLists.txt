cmake_minimum_required(VERSION 3.16)
project(TellNumber C)

set(CMAKE_C_STANDARD 11)

add_executable(TellNumber main.c common.h screenOut.c screenOut.h phoneData.h phoneFunc.c phoneFunc.h)