#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"


int main()
{

    auto img =
        visionlite::BMP::load(
            "assets/input/test.bmp"
        );


 auto graysclae =
    visionlite::Filters::grayscale(
        img
    );

visionlite::BMP::save(
    "assets/output/new-grayscale.bmp",
     graysclae
);

    return 0;
}