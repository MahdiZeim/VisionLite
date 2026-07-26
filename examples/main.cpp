#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"


int main()
{

    auto img =
        visionlite::BMP::load(
            "assets/input/test.bmp"
        );


auto binary =
    visionlite::Filters::threshold(
        img,
        128
    );


visionlite::BMP::save(
    "assets/output/threshold.bmp",
    binary
);

    return 0;
}