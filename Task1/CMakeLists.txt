cmake_minimum_required(VERSION 3.16)
project(Task1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(main main/main.cpp src/task1.cpp)

add_executable(tests tests/tests.cpp src/task1.cpp)
target_link_libraries(tests gtest gtest_main)