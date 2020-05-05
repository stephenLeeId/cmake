#configure variables
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(day1)

# 是否使用自己的 Math库

option (USE_Detect_A "Use provided math implementation" OFF)
option (USE_Detect_B "Use provided math implementation" OFF)
option (USE_Detect_C "Use provided math implementation" OFF)
# 用于测试替换用的变量

if(USE_Detect_A)

message("USE_Detect_A #############")
add_definitions(-DUSE_Detect_A)

elseif(USE_Detect_B)

message("USE_Detect_B #############")
add_definitions(-DUSE_Detect_B)

elseif(USE_Detect_C)

add_definitions(-DUSE_Detect_C)
message("USE_Detect_C #############")

else()

message("USE_Detect #############")
add_definitions(-DUSE_Detect)

endif()


add_compile_options(-std=c++11)

add_executable(day1 main.cpp myLog.cpp)


# 如果是多个文件
#add_executable(day1 main.cpp　b.cpp c.cpp d.cpp myLog.cpp)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
#aux_source_directory(. DIR_SRCS)
#add_executable(day1 ${DIR_SRCS})




