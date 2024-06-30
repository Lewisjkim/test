project(
  testlib
  VERSION 0.1.0
  LANGUAGES C CXX)

add_library(testlib STATIC week01/week01.cpp)
add_library(testlib2 STATIC week02/week02.cpp)
add_library(testlib3 STATIC week03/week03.cpp)
add_subdirectory(week01/week01Tests)
add_subdirectory(week02/week02Tests)
add_subdirectory(week03/week03Tests)
