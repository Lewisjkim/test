
project(testlib VERSION 0.1.0 LANGUAGES C CXX)

add_library(testlib STATIC week01.cpp)
add_library(testlib2 STATIC week02.cpp)
add_subdirectory(week01)
add_subdirectory(week02)
