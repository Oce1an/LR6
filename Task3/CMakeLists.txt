cmake_minimum_required(VERSION 3.16)
project(Task3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_CLANG_TIDY 
    clang-tidy;
    -checks=*;
    -header-filter=.*
)

set(SANITIZER_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
    
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
    
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")

add_executable(main src/task3.cpp)