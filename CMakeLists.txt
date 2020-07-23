cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(stl_like_containers)

function(addProgramTarget)
    set(OPTIONAL_ARGUMENTS_PATTERN
      )
      
    set(ONE_ARGUMENT_PATTERN
      TARGET_NAME
      )
      
    set(MULTI_ARGUMENT_PATTERN
      SRC_FILES
      PUBLIC_INC_DIRS
      PUBLIC_LINK_LIBS
      PUBLIC_DEFINES
      )
    
    CMake_parse_arguments(ARG 
      "${OPTIONAL_ARGUMENTS_PATTERN} "
      "${ONE_ARGUMENT_PATTERN}"
      "${MULTI_ARGUMENT_PATTERN}"
      ${ARGN})

    addTarget(
      TARGET_NAME "${ARG_TARGET_NAME}"
      TEST_NAME "${ARG_TARGET_NAME}"
      SRC_FILES "${ARG_SRC_FILES}"
      PUBLIC_INC_DIRS "${ARG_PUBLIC_INC_DIRS};${PLATFORM_INCLUDE_PATH}"
      PUBLIC_LINK_LIBS "${ARG_PUBLIC_LINK_LIBS}"
      PUBLIC_DEFINE "${ARG_PUBLIC_DEFINES}"
    )
  endfunction()


function(addUtilTarget)
    set(OPTIONAL_ARGUMENTS_PATTERN
      )
      
    set(ONE_ARGUMENT_PATTERN
      TARGET_NAME
      )
      
    set(MULTI_ARGUMENT_PATTERN
      SRC_FILES
      PUBLIC_INC_DIRS
      PUBLIC_LINK_LIBS
      PUBLIC_DEFINES
      )
    
    CMake_parse_arguments(ARG 
      "${OPTIONAL_ARGUMENTS_PATTERN} "
      "${ONE_ARGUMENT_PATTERN}"
      "${MULTI_ARGUMENT_PATTERN}"
      ${ARGN})

    addTarget(
      TARGET_NAME "${ARG_TARGET_NAME}"
      SRC_FILES "${ARG_SRC_FILES}"
      PUBLIC_INC_DIRS "${ARG_PUBLIC_INC_DIRS};${PLATFORM_INCLUDE_PATH}"
      PUBLIC_LINK_LIBS "${ARG_PUBLIC_LINK_LIBS}"
      PUBLIC_DEFINE  "${ARG_PUBLIC_DEFINES}"
    )
  endfunction()

set(TARGET_NAME
    "STL_Main"    
)

set(SRC_FILES 
    container_test.cpp
    )

set(INC_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/utils"
)

set(LIBS
    linked_list
    vector
)

addProgramTarget(
    TARGET_NAME "${TARGET_NAME}"
    SRC_FILES "${SRC}"
    PUBLIC_INC_DIRS "${INC_DIR}"
    PUBLIC_LINK_LIBS "${LIBS}"
)

add_subdirectory(utils)