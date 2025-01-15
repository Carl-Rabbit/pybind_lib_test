#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "py/func/pyfunc.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(test_module, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: test_module

        .. autosummary::
           :toctree: _generate

           add_arrays_1d
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two double numbers
    )pbdoc");

    m.def("add_arrays_1d", &add_arrays_1d, R"pbdoc(
        Add two 1d arrays
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}