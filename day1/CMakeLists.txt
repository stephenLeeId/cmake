cmake_minimum_required(VERSION 3.0)
project(day1)

add_executable(day1 main.cpp add.cpp)

# 如果是多个文件
#add_executable(day1 main.cpp　b.cpp c.cpp d.cpp)

aux_source_directory(. DIR_SRCS)
message("DIR_SRCS = ${DIR_SRCS}")

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
#aux_source_directory(. DIR_SRCS)
#add_executable(day1 ${DIR_SRCS})




