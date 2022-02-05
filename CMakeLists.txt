cmake_minimum_required(VERSION 3.5)

project(rope LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#parser.cpp
#--------
#set(Parser_lib parser.cpp)
#add_library(parser STATIC Parser_lib)
#-------
add_executable(rope main.cpp wordconvertor.cpp parser.cpp)
