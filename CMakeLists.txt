cmake_minimum_required(VERSION 3.29.5) # 최상위 버전을 다운 받아서 사용해라
project(
  ExampleDoctest
  VERSION 0.1.0
  DESCRIPTION "Testcase executable using DocTest"
  LANGUAGES C CXX)

# download CPM.cmake
file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH
    SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)
# 최상위에 cpm
cpmaddpackage("gh:onqtam/doctest@2.4.9")

include(CTest)
set(CMAKE_CXX_STANDARD 20)
# required
add_subdirectory(src)
