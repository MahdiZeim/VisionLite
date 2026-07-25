#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"


int main()
{

    auto img =
        visionlite::BMP::load(
            "assets/input/test.bmp"
        );


  auto bright = visionlite::Filters::brightness(
    img,
    40
    );

    visionlite::BMP::save(
    "assets/output/bright.bmp",
    bright
    );


    return 0;
}