cmake_minimum_required(VERSION 3.10)
project(MDReader)

set(CMAKE_CXX_STANDARD 14)

add_executable(MDReader main.cpp regexRules.cpp regexRules.h)