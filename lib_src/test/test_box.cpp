#include "cls/box.hpp"

int main() {
    std::unique_ptr<Box<int>> red_box = mk_box<int>("RedBox");
    printf("red_box->dtype() = %s\n", red_box->dtype().c_str());
    printf("red_box->type() = %s\n", red_box->type().c_str());
    red_box->put(1);
    red_box->get();
    printf("red_box->get() = %d\n", red_box->get());

    std::unique_ptr<Box<double>> blue_box = mk_box<double>("BlueBox");
    printf("blue_box->dtype() = %s\n", blue_box->dtype().c_str());
    printf("blue_box->type() = %s\n", blue_box->type().c_str());
    blue_box->put(2.0);
    printf("blue_box->get() = %f\n", blue_box->get());

    return 0;
}