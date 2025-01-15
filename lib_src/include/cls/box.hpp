#pragma once
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>


template <typename DType = float>
struct Box {
    DType value;
    Box() { }
    virtual void put(DType value) = 0;
    virtual DType get() const = 0;
    virtual std::string type() const = 0;
    std::string dtype() const {
        return typeid(DType).name();
    }
};

template <typename DType = float>
struct RedBox : Box<DType> {
    RedBox() : Box<DType>() { }
    void put(DType value) override {
        this->value = value;
    }
    DType get() const override {
        return this->value;
    }
    std::string type() const override {
        return "RedBox";
    }
};

template <typename DType = float>
struct BlueBox : Box<DType> {
    BlueBox() : Box<DType>() { }
    void put(DType value) override {
        this->value = value;
    }
    DType get() const override {
        return this->value;
    }
    std::string type() const override {
        return "BlueBox";
    }
};

template <typename DType = float>
std::unique_ptr<Box<DType>> mk_box(const std::string &type) {
    if (type == "RedBox") {
        return std::make_unique<RedBox<DType>>();
    } else if (type == "BlueBox") {
        return std::make_unique<BlueBox<DType>>();
    }
    throw std::runtime_error("Unknown box type: " + type);
}