cmake_minimum_required(VERSION 3.5)
project(my_test)

# you may need these 2 lines, and set your own paths
# set(PYTHON_EXECUTABLE "/usr/bin/python3.8")
# set(PYTHON_INCLUDE_DIRECTORY "/usr/include/python3.8/Python.h")

add_subdirectory(extern/pybind11)
pybind11_add_module(my_test my_test.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(my_test
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})