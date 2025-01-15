cmake_minimum_required(VERSION 3.5)
project(test_module)

add_subdirectory(third_party/pybind11)

include_directories(include)
add_subdirectory(src)
