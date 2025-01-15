pybind11_add_module(test_module pybind.cpp)

target_link_libraries(test_module PRIVATE lib_func)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(test_module
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})