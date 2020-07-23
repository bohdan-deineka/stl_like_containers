cmake_minimum_required(VERSION 2.8)

set(SRC_DIR 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

set(SRC 
    "${SRC_DIR}/vector.cpp"
)

set(INC_DIR 
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)

addUtilTarget(
    TARGET_NAME vector 
    SRC_FILES ${SRC}
    PUBLIC_INC_DIRS ${INC_DIR}
)