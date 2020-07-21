cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(linked_list_src_files
    linked_list.cpp
)

add_library(linked_list SHARED ${linked_list_src_files})