#configure variables
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(myProject)


# 设置二进制可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# 设置库文件输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


aux_source_directory(. DIR_SRCS)
aux_source_directory(./src/java_interface DIR_SRCS)
aux_source_directory(./src/add DIR_SRCS)
aux_source_directory(./src/sum DIR_SRCS)


add_compile_options(-std=c++11)
if(WIN32)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
	message("linux .....")
endif()

if(ANDROID)

set(NDK_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../android-ndk-r18b)

message("ANDROID123........ "  ${NDK_ROOT} )
include_directories(${NDK_ROOT}/sysroot/usr/include)
include_directories(${NDK_ROOT}/sources/cxx-stl/llvm-libc++/include)

else()

#include_directories("/home/zhangli/workplace/cmake_study/jdk1.8.0_231/include" 
#"/home/zhangli/workplace/cmake_study/jdk1.8.0_231/include/linux") 

include_directories("$ENV{JAVA_HOME}/include" 
"$ENV{JAVA_HOME}/include/linux") 
endif()


if(ANDROID)

add_library(${CMAKE_PROJECT_NAME}_shared SHARED ${DIR_SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME}_shared log)
set_target_properties(${CMAKE_PROJECT_NAME}_shared PROPERTIES 
	OUTPUT_NAME "${CMAKE_PROJECT_NAME}")


add_library(${CMAKE_PROJECT_NAME}_static STATIC ${DIR_SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME}_static log)
set_target_properties(${CMAKE_PROJECT_NAME}_static PROPERTIES 
	OUTPUT_NAME "${CMAKE_PROJECT_NAME}")

else()

# 生成myProject_shared动态库文件
add_library(${CMAKE_PROJECT_NAME}_shared SHARED ${DIR_SRCS})
# 链接需要用到的库文件pthread
target_link_libraries(${CMAKE_PROJECT_NAME}_shared pthread)
# 修改库文件名称为myProject，系统自动改为libmyProject
set_target_properties(${CMAKE_PROJECT_NAME}_shared PROPERTIES 
	OUTPUT_NAME "${CMAKE_PROJECT_NAME}")

# 生成myProject_static静态库文件
add_library(${CMAKE_PROJECT_NAME}_static STATIC ${DIR_SRCS})
# 链接需要用到的库文件pthread
target_link_libraries(${CMAKE_PROJECT_NAME}_static pthread)
# 修改库文件名称为myProject，系统自动改为libmyProject
set_target_properties(${CMAKE_PROJECT_NAME}_static PROPERTIES 
	OUTPUT_NAME "${CMAKE_PROJECT_NAME}")


endif()

include_directories("src/add" "src/sum")

add_subdirectory(example)


set(INSTALL_PATH_LIB lib)
set(INSTALL_PATH_INCLUDE include)

install(DIRECTORY src/sum DESTINATION ${INSTALL_PATH_INCLUDE} FILES_MATCHING PATTERN "*.h")
install(DIRECTORY src/add DESTINATION ${INSTALL_PATH_INCLUDE} FILES_MATCHING PATTERN "*.h")

if(WIN32)
install(TARGETS ${CMAKE_PROJECT_NAME}_shared RUNTIME DESTINATION ${INSTALL_PATH_LIB})
else()
install(TARGETS ${CMAKE_PROJECT_NAME}_shared LIBRARY DESTINATION ${INSTALL_PATH_LIB})
endif()

install(TARGETS ${CMAKE_PROJECT_NAME}_static ARCHIVE DESTINATION ${INSTALL_PATH_LIB})





