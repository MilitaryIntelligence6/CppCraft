cmake_minimum_required(VERSION 3.20)
project(CppMinecraft CXX C)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

FILE(GLOB SOURCE_FILES
        src/main/cpp/*/*.h
        src/main/cpp/*/*.cpp
#        src/main/cpp/*/*/*.h
#        src/main/cpp/*/*/*.c
        src/main/cpp/main.cpp
        )

add_executable(CppMinecraft
        ${SOURCE_FILES}
        deps/glew/src/glew.c
        deps/lodepng/lodepng.cpp
        deps/noise/noise.cpp
        deps/sqlite/sqlite3.c
        deps/tinycthread/source/tinycthread.c
        )

#add_definitions(-std=c99 -O3)

add_subdirectory(deps/glfw)

include_directories(src/main/cpp/config)
include_directories(src/main/cpp/controller)
include_directories(src/main/cpp/dao)
include_directories(src/main/cpp/datastruct)
include_directories(src/main/cpp/entity)
include_directories(src/main/cpp/graphic)
include_directories(src/main/cpp/include)
include_directories(src/main/cpp/scene)
include_directories(src/main/cpp/user)
include_directories(src/main/cpp/util)
include_directories(src/main/cpp/view)
#include_directories(src/main/cpp/lib/tinycthread)

include_directories(deps/glew/include)
include_directories(deps/glfw/include)
include_directories(deps/lodepng)
include_directories(deps/noise)
include_directories(deps/sqlite)
include_directories(deps/tinycthread/source)

#if(MINGW)
#    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH}
#            "C:/Program Files/CURL/lib" "C:/Program Files (x86)/CURL/lib")
#    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH}
#            "C:/Program Files/CURL/include" "C:/Program Files (x86)/CURL/include")
#endif()

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

if(APPLE)
    target_link_libraries(CppMinecraft glfw
            ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

if(UNIX)
    target_link_libraries(CppMinecraft dl glfw
            ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

if(MINGW)
    target_link_libraries(CppMinecraft ws2_32.lib glfw
            ${GLFW_LIBRARIES} ${CURL_LIBRARIES})
endif()

