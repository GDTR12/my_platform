

# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
cmake_minimum_required(VERSION 3.16.3)
project(xui)

set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-gcc)


set(COMPILE_FLAGS "-O2 -march=armv7-a -mcpu=cortex-a9 -mlittle-endian -mfloat-abi=soft -mno-sched-prolog -mno-unaligned-access -fPIC -fno-exceptions \
    -fno-common -fno-inline -fno-omit-frame-pointer -fno-strict-aliasing -fno-merge-constants \
    -freg-struct-return -fno-delete-null-pointer-checks -fstack-protector-strong -pipe\
    -Wtrampolines -Wall -Wfloat-equal -Wshadow"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lstdc++ -lm")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

# 判断编译器类型,如果是gcc编译器,则在编译选项中加入c++11支持
if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-std=c++11)
    message(STATUS "optional:-std=c++11")   
endif(CMAKE_COMPILER_IS_GNUCXX)

aux_source_directory(./src DIRSRCS)
# Make an automatic library - will be static or dynamic based on user setting
add_library(xui STATIC ${DIRSRCS})
# set_target_properties(xui )
target_include_directories(xui PUBLIC ./includes ./src)


