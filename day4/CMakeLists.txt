#configure variables
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(myProject)



# 设置二进制可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# 设置库文件输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


aux_source_directory(. DIR_SRCS)
aux_source_directory(./src/add DIR_SRCS)
aux_source_directory(./src/sum DIR_SRCS)



# 生成myProject_shared动态库文件
add_library(${CMAKE_PROJECT_NAME}_shared SHARED ${DIR_SRCS})
# 链接需要用到的库文件pthread
#target_link_libraries(${CMAKE_PROJECT_NAME}_shared pthread)
# 修改库文件名称为myProject，系统自动改为libmyProject
set_target_properties(${CMAKE_PROJECT_NAME}_shared PROPERTIES 
	OUTPUT_NAME "${CMAKE_PROJECT_NAME}")

# 生成myProject_static静态库文件
add_library(${CMAKE_PROJECT_NAME}_static STATIC ${DIR_SRCS})
# 链接需要用到的库文件pthread
#target_link_libraries(${CMAKE_PROJECT_NAME}_static pthread)
# 修改库文件名称为myProject，系统自动改为libmyProject
set_target_properties(${CMAKE_PROJECT_NAME}_static PROPERTIES 
	OUTPUT_NAME "${CMAKE_PROJECT_NAME}")


#include_directories("src/add" "src/sum")

add_subdirectory(example)






