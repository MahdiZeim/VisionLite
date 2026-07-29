#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"
#include "visionlite/kernel.hpp"
#include <iostream>

int main()
{

    auto img =
        visionlite::BMP::load(
            "assets/input/test.bmp"
        );

/*
auto binary =
    visionlite::Filters::threshold(
        img,
        128
    );


visionlite::BMP::save(
    "assets/output/threshold.bmp",
    binary
);
*/

auto blur = visionlite::Kernel::boxBlur(3);

std::cout 
    << "Blur sum: "
    << blur.sum()
    << std::endl;


auto gaussian = visionlite::Kernel::gaussian3x3();

std::cout
    << "Gaussian sum: "
    << gaussian.sum()
    << std::endl;

    return 0;
}