aux_source_directory(. TEST_SRC_LIST)
foreach(TEST_SRC ${TEST_SRC_LIST})
    STRING(REGEX REPLACE "^\\./|\\.c[a-zA-Z0-9_]*$" "" TEST_EXE_NAME ${TEST_SRC})  # 字符串处理，去掉前面路径和后缀
    message(STATUS "添加测试程序:${TEST_EXE_NAME}")
    add_executable(${TEST_EXE_NAME} ${TEST_SRC})
    target_link_libraries(${TEST_EXE_NAME} ${CMAKE_PROJECT_NAME}_shared)
endforeach(TEST_SRC ${TEST_SRC_LIST})