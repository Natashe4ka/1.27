cmake_minimum_required(VERSION 2.8)

project(n1.27)

set(n1.27_src main.cpp QUEUE.cpp AT.cpp)
set(n1.27_hdr head.hpp QUEUE.hpp AT.hpp)

add_executable(${PROJECT_NAME} ${n1.27_src} ${n1.27_hdr})

