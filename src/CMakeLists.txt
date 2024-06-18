cmake_minimum_required(VERSION 3.12)
project(testlib VERSION 0.1.0 LANGUAGES C CXX)

add_library(testlib STATIC week01.cpp)

add_subdirectory(week01)
