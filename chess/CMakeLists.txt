# cmake_minimum_required(VERSION <specify CMake version here>)
project(chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(chess main.cpp temp.h temp.cc AI/positionValue.h AI/AIClass.cpp AI/AIClass.h)

set(BOOST_ROOT "C:\\Users\\Krzysiek\\Documents\\Studia\\sem5\\ZPR\\boost_1_71_0")
set(BOOSTROOT "C:\\Users\\Krzysiek\\Documents\\Studia\\sem5\\ZPR\\boost_1_71_0")
set(Boost_INCLUDE_DIR "C:\\Users\\Krzysiek\\Documents\\Studia\\sem5\\ZPR\\boost_1_71_0")

target_link_libraries(chess python3.6m)

find_package(Boost 1.71.0)

if(Boost_FOUND)
    message(STATUS "It works!")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()