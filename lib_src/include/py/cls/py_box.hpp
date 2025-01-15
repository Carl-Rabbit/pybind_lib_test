#pragma once
#include <memory>
#include <string>
#include <variant>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "cls/box.hpp"

namespace py = pybind11;

using BoxPtrType = std::variant<std::unique_ptr<Box<int>>, std::unique_ptr<Box<double>>>;

BoxPtrType mk_py_box(const std::string &type, const py::dtype &dtype) {
    if (type == "RedBox") {
        if (dtype.is(py::dtype::of<int>())) {
            return std::make_unique<RedBox<int>>();
        } else if (dtype.is(py::dtype::of<double>())) {
            return std::make_unique<RedBox<double>>();
        }
    } else if (type == "BlueBox") {
        if (dtype.is(py::dtype::of<int>())) {
            return std::make_unique<BlueBox<int>>();
        } else if (dtype.is(py::dtype::of<double>())) {
            return std::make_unique<BlueBox<double>>();
        }
    }
    throw std::runtime_error("Unknown box: type=" + type + ", dtype=" + py::cast<std::string>(dtype));
}