cmake_minimum_required(VERSION 3.10)
project(BankAccountProject)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell compiler where to find headers
include_directories(include)

# Define the executable and source files
add_executable(bank_app
    src/main.cpp
    src/BankAccount.cpp
)
