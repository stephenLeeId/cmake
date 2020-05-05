#configure variables
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(test3)

aux_source_directory(. DIR_SRCS)
# aux_source_directory(../src/add DIR_SRCS)
# aux_source_directory(../src/sum DIR_SRCS)


include_directories("./../src/add" "./../src/sum")
link_directories("./../build")

message("day3 test DIR_SRCS = ${DIR_SRCS}")
add_executable(test3 ${DIR_SRCS})

target_link_libraries(test3 day3)


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
#aux_source_directory(. DIR_SRCS)
#add_executable(day1 ${DIR_SRCS})




