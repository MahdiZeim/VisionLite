#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"


int main()
{

    auto img =
        visionlite::BMP::load(
            "assets/input/test.bmp"
        );


 auto contrast =
    visionlite::Filters::contrast(
        img,
        1.5f
    );

visionlite::BMP::save(
    "assets/output/contrast.bmp",
    contrast
);

    return 0;
}