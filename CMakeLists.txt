cmake_minimum_required(VERSION 3.12)
project(
    ExampleDoctest
    VERSION 0.1.0 
    DESCRIPTION "Testcase executable using DocTest" 
    LANGUAGES C CXX
)

include(CTest)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)