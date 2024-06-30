project(
  testprogram2
  VERSION 0.1.0
  LANGUAGES C CXX)

# 실행파일 생성
add_executable(program02 week02.spec.cpp)
# ---- Create binary ----

target_link_libraries(program02 doctest::doctest)
target_link_libraries(program02 testlib2)
target_compile_features(program02 PRIVATE cxx_std_20)

# ---- enable test ----
# enable_testing() add_test(program02 program02)
