cmake_minimum_required(VERSION 3.10)

project(RandomVector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(random_vector
  main.cpp
  random_vector.cpp
)
