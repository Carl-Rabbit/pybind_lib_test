#!/bin/bash
docker build -t pybind_lib_test .
docker run pybind_lib_test