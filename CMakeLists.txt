cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(stl_like_containers)

set(SRC_FILES 
    container_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/vector/vector.cpp
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils/vector)

add_executable(
    stl_main
    ${SRC_FILES}
)

target_link_libraries(stl_main vector)

add_subdirectory(utils)