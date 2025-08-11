cmake_minimum_required(VERSION 3.10)
project(ExpressionProject)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell compiler where to find headers
include_directories(include)

# Define the executable and source files
add_executable(express
    src/main.cpp
    src/Expression.cpp
)
