#configure variables
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(day3)

aux_source_directory(. DIR_SRCS)
aux_source_directory(./src/add DIR_SRCS)
aux_source_directory(./src/sum DIR_SRCS)

message("DIR_SRCS = ${DIR_SRCS}")
#add_executable(dayRun ${DIR_SRCS})

#add_library(day3 SHARED  ${DIR_SRCS})
add_library(day3 STATIC  ${DIR_SRCS})

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
#aux_source_directory(. DIR_SRCS)
#add_executable(day1 ${DIR_SRCS})




