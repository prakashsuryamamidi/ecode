project (ecode)
cmake_minimum_required(VERSION 3.1)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_compile_options(-std=c++17)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

add_library(ecode STATIC ${SRC_DIR}/ecode.cpp
                         ${SRC_DIR}/utils.cpp)

add_executable(test-ecode ${TEST_DIR}/test_ecode.cpp)
target_link_libraries(test-ecode ecode)

