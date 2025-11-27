cmake_minimum_required(VERSION 3.16)
project(Task2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_CLANG_TIDY clang-tidy)
#set(CMAKE_CXX_CLANG_TIDY 
#    clang-tidy;
#    -checks=*;
#    -header-filter=.*
#)
set(SANITIZER_FLAGS "-fsanitize=address -fno-omit-frame-pointer")

include(FetchContent)
FetchContent_Declare(
  googletest  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(main main/main.cpp src/task2.cpp)
add_executable(tests tests/tests.cpp src/task2.cpp)
target_link_libraries(tests gtest gtest_main)