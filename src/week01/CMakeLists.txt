cmake_minimum_required(VERSION 3.12)
project(testprogram VERSION 0.1.0 LANGUAGES C CXX)

# set()
include(CTest)
# download CPM.cmake
file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake   
  EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:onqtam/doctest@2.4.9")
# 실행파일 생성
add_executable(program01 week01.spec.cpp)
# ---- Create binary ----

target_link_libraries(program01 doctest)
target_link_libraries(program01 testlib)
target_compile_features(program01 PRIVATE cxx_std_20)


# ---- enable test ----
enable_testing()
add_test(program01 program01)