#include <iostream>

#include "visionlite/bmp.hpp"


int main()
{

    auto img =
        visionlite::BMP::load(
            "assets/input/test.bmp"
        );


    visionlite::BMP::save(
        "assets/output/result.bmp",
        img
    );


    return 0;
}