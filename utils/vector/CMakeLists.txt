cmake_minimum_required(VERSION 2.8)

project(vector)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(vector_src_files
    vector.cpp
)

add_library(vector STATIC ${vector_src_files})