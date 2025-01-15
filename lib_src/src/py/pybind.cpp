#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include "py/func/py_func.h"
#include "py/cls/py_pet.hpp"
#include "py/cls/py_box.hpp"

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

    // func

    m.def("add", &add, R"pbdoc(
        Add two double numbers
    )pbdoc");

    m.def("add_arrays_1d", &add_arrays_1d, R"pbdoc(
        Add two 1d arrays
    )pbdoc");

    // cls

    py::class_<Pet>(m, "Pet")
        .def_readwrite("name", &Pet::name);

    py::class_<Dog, Pet>(m, "Dog")
        .def(py::init<const std::string &>())
        .def("sound", &Dog::sound);

    m.def("mk_pet", &mk_pet, R"pbdoc(
        Create a pet
    )pbdoc", py::arg("type"), py::arg("name"));

    py::class_<Box<int>>(m, "BoxInt")
        .def("put", &Box<int>::put)
        .def("get", &Box<int>::get)
        .def("dtype", &Box<int>::dtype)
        .def("type", &Box<int>::type);
    
    py::class_<Box<double>>(m, "BoxDouble")
        .def("put", &Box<double>::put)
        .def("get", &Box<double>::get)
        .def("dtype", &Box<double>::dtype)
        .def("type", &Box<double>::type);

    py::class_<RedBox<int>, Box<int>>(m, "RedBoxInt");
    py::class_<RedBox<double>, Box<double>>(m, "RedBoxDouble");
    py::class_<BlueBox<int>, Box<int>>(m, "BlueBoxInt");
    py::class_<BlueBox<double>, Box<double>>(m, "BlueBoxDouble");

    m.def("mk_box", &mk_py_box, R"pbdoc(
        Create a box
    )pbdoc", py::arg("type"), py::arg("dtype"));

    // version

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}