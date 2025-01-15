#pragma once
#include <memory>
#include <string>
#include <pybind11/pybind11.h>

#include "cls/pet.hpp"

std::unique_ptr<Pet> mk_pet(const std::string &type, const std::string &name) {
    if (type == "Dog") {
        return std::make_unique<Dog>(name);
    }
    throw std::runtime_error("Unknown pet type: " + type);
}
