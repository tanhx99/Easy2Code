cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES *.cpp)
foreach(A_CPP_FILE ${SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${A_CPP_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${A_CPP_FILE})
endforeach(A_CPP_FILE ${SOURCE_FILES})
