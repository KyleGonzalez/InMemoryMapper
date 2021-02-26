cmake_minimum_required(VERSION 3.19)
project(InMemoryMap)

set(CMAKE_CXX_STANDARD 14)

add_executable(InMemoryMap main.cpp inmemory/InMemoryMap.cpp inmemory/InMemoryMap.h exception/NotEnoughMemoryException.cpp exception/NotEnoughMemoryException.h)