cmake_minimum_required(VERSION 3.16.3)

project(my_platform)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_C_FLAGS -Wno-format)


add_subdirectory(./third_party)

add_subdirectory(./components/test)
add_subdirectory(./components/list_template_c)
add_subdirectory(./components/xui)
add_subdirectory(./components/cJSON)

# add_subdirectory(./app/test)
add_subdirectory(./app/cpp_relearn)
# ================================== 常见变量 ========================================

# PROJECT_NAME：                            返回通过 project 命令定义的项目名称
# PROJECT_SOURCE_DIR                        工程的根目录
# PROJECT_BINARY_DIR                        运行cmake命令的目录，通常为${PROJECT_SOURCE_DIR}/build
# PROJECT_VERSION_MAJOR
# PROJECT_VERSION_MINOR
# PROJECT_VERSION_PATCH

# CMAKE_C_COMPILER                          set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc)
# CMAKE_CXX_COMPILER                        set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-g++)
# COMPILE_FLAGS                             同时包含C_FLAGS和CXX_FLAGS                                
# CMAKE_C_FLAGS                             
# CMAKE_CXX_FLAGS
# CMAKE_COMPILER_IS_GNUCC                   if(CMAKE_COMPILER_IS_GNUCC) ... endif 
# CMAKE_COMPILER_IS_GNUCXX
# CMAKE_COMPILER_IS_GNUG77

# CMAKE_CURRENT_SOURCE_DIR：                当前处理的 CMakeLists.txt 所在的路径
# CMAKE_CURRENT_BINARY_DIR：                target 编译目录
# CMAKE_CURRENT_LIST_DIR：                  CMakeLists.txt 的完整路径
# CMAKE_CURRENT_LIST_FILE                   /home/gdtr/AI/my_platform/CMakeLists.txt
# CMAKE_CURRENT_LIST_LINE

# CMAKE_SOURCE_DIR

# CMAKE_SYSTEM                              查询当前系统，例如：Linux-5.15.0-58-generic
# CMAKE_SYSTEM_NAME                         查询当前系统，例如：Linux
# CMAKE_SYSTEM_VERSION                      查询当前系统，例如：5.15.0-58-generic
# CMAKE_SYSTEM_PROCESSOR                    查询当前系统，例如：x86_64

# EXECUTABLE_OUTPUT_PATH：                  重新定义目标二进制可执行文件的存放位置
# LIBRARY_OUTPUT_PATH：                     重新定义目标链接库文件的存放位置

#[[

message([<mode>] "message text" ...)
 <mode> 表示模式，可以为: STATUS, WARNING, AUTHOR_WARNING, SEND_ERROR, FATAL_ERROR, DEPRECATION, NOTICE, VERBOSE, DEBUG, TRACE



]]#



message("")
message("====== check variables: ===========")
message("${COMPILE_FLAGS}")
message("====== check variables: ===========")
message("")
