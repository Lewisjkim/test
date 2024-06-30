project(
  testprogram
  VERSION 0.1.0
  LANGUAGES C CXX)

# 실행파일 생성
add_executable(program01 week01.spec.cpp)
# ---- Create binary ----

target_link_libraries(program01 doctest::doctest)
target_link_libraries(program01 testlib)
target_compile_features(program01 PRIVATE cxx_std_20)

# ---- enable test ----
# enable_testing() add_test(program01 program01)
