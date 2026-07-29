#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"
#include "visionlite/kernel.hpp"
#include "visionlite/convolution.hpp"
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
    auto kernel =
    visionlite::Kernel::boxBlur(3);


auto blurred =
    visionlite::Convolution::apply(
        img,
        kernel
    );

visionlite::BMP::save(
    "assets/output/blur.bmp",
    blurred
);


    return 0;
}