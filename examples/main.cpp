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

   
auto cropCenter =
    visionlite::Transform::crop(
        img,
        img.getWidth() / 4,
        img.getHeight() / 4,
        img.getWidth() / 2,
        img.getHeight() / 2
    );

visionlite::BMP::save(
    "assets/output/crop_center.bmp",
    cropCenter
);

auto cropCorner =
    visionlite::Transform::crop(
        img,
        0,
        0,
        200,
        200
    );

visionlite::BMP::save(
    "assets/output/crop_corner.bmp",
    cropCorner
);

    return 0;
}