#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "func/add.h"
#include "py/func/py_func.h"

namespace py = pybind11;

py::array_t<double> add_arrays_1d(py::array_t<double>& input1, py::array_t<double>& input2) {
    // 获取input1, input2的信息
    py::buffer_info buf1 = input1.request();
    py::buffer_info buf2 = input2.request();

    if (buf1.ndim !=1 || buf2.ndim !=1)
    {
        throw std::runtime_error("Number of dimensions must be one");
    }

    if (buf1.size !=buf2.size)
    {
        throw std::runtime_error("Input shape must match");
    }

    //申请空间
    auto result = py::array_t<double>(buf1.size);
    py::buffer_info buf3 = result.request();

    //获取numpy.ndarray 数据指针
    double* ptr1 = (double*)buf1.ptr;
    double* ptr2 = (double*)buf2.ptr;
    double* ptr3 = (double*)buf3.ptr;

    //指针访问numpy.ndarray
    for (int i = 0; i < buf1.shape[0]; i++)
    {
        ptr3[i] = add(ptr1[i], ptr2[i]);
    }

    return result;
}