project(
  testprogram3
  VERSION 0.1.0
  LANGUAGES C CXX)

# 실행파일 생성
add_executable(program03 week03.spec.cpp)
# ---- Create binary ----

target_link_libraries(program03 doctest::doctest)
target_link_libraries(program03 testlib3)
target_compile_features(program03 PRIVATE cxx_std_20)

# ---- enable test ----
enable_testing()
add_test(program03 program03)
