cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(sol2-test)

#################################################
# CMAKE SETTINGS
#################################################
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include (Modules/download_file)


#################################################
# THIRD PARTY SETTINGS
#################################################
enable_testing()
include(cmake/thirdparty/Catch.cmake)
include(cmake/thirdparty/Lua.cmake)
include(cmake/thirdparty/Sol2.cmake)

#################################################
# COMPILER SETTINGS
#################################################
message(STATUS "-------------------------------------------------")
message(STATUS "Configuring compiler")

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_COMPILER "clang")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libstdc++ -O3 -Werror")
message(STATUS "Compiler : ${CMAKE_CXX_COMPILER}")
message(STATUS "Flags    : ${CMAKE_CXX_FLAGS}")
message(STATUS "-------------------------------------------------")

add_executable(sol2-test
    src/Interpreter.cpp
    src/Node.cpp
    src/NodeDescriptor.cpp
    src/Registry.cpp
    src/main.cpp
    )

target_include_directories(sol2-test
    PUBLIC
    include
)

target_link_libraries(sol2-test
    stdc++
    m
    dl
    lua
    sol
)
