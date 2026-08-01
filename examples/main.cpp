#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"
#include "visionlite/kernel.hpp"
#include "visionlite/convolution.hpp"
#include "visionlite/analyzer.hpp"
#include "visionlite/enhancer.hpp"
#include "visionlite/morphology.hpp"
#include "visionlite/transform.hpp"

#include <iostream>

int main()
{

    auto img =
        visionlite::BMP::load(
            "assets/input/test.bmp"
        );

        std::cout << "Loaded image: "
          << img.getWidth()
          << " x "
          << img.getHeight()
          << " ("
          << img.getChannels()
          << " channels)"
          << std::endl;
          
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
/*
auto edgeY =
    visionlite::Filters::edgeDetectY(
        img
    );

visionlite::BMP::save(
    "assets/output/edge_y.bmp",
    edgeY
);
*/

/*auto min =
    visionlite::Analyzer::minIntensity(img);


auto max =
    visionlite::Analyzer::maxIntensity(img);


std::cout
    << "Min intensity: "
    << (int)min
    << std::endl;


std::cout
    << "Max intensity: "
    << (int)max
    << std::endl;
*/

/*float contrast =
    visionlite::Analyzer::contrast(img);


std::cout
    << "Contrast: "
    << contrast
    << std::endl;*/


auto rotate45 =
    visionlite::Transform::rotate(img, 45);

visionlite::BMP::save(
    "assets/output/rotate45.bmp",
    rotate45
);

auto rotate90 =
    visionlite::Transform::rotate(img, 90);

visionlite::BMP::save(
    "assets/output/rotate90.bmp",
    rotate90
);

auto rotate180 =
    visionlite::Transform::rotate(img, 180);

visionlite::BMP::save(
    "assets/output/rotate180.bmp",
    rotate180
);

auto rotate270 =
    visionlite::Transform::rotate(img, 270);

visionlite::BMP::save(
    "assets/output/rotate270.bmp",
    rotate270
);

    return 0;
}