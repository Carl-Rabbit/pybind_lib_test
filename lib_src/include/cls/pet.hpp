#pragma once
#include <string>

struct Pet {
    Pet(const std::string &name) : name(name) { }
    std::string name;
    virtual std::string sound() const = 0;
};

struct Dog : Pet {
    Dog(const std::string &name) : Pet(name) { }
    std::string sound() const override { return "woof!"; }
};