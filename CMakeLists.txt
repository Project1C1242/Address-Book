cmake_minimum_required(VERSION 3.10)

# Name
project(Address-Book VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add your source files here as you create them
set(SOURCES
    src/main.cpp
    src/AddressBook.h
    src/Contact.cpp
    src/Contact.h
    src/Person.cpp
    src/Person.h
    src/Business.cpp
    src/Business.h
    src/Vendor.cpp
    src/Vendor.h
    src/Emergency.cpp
    src/Emergency.h
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})