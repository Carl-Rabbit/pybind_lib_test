#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "func/add.h"

namespace py = pybind11;

py::array_t<double> add_arrays_1d(py::array_t<double>& input1, py::array_t<double>& input2);