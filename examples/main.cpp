#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"
#include "visionlite/kernel.hpp"
#include "visionlite/convolution.hpp"
#include "visionlite/analyzer.hpp"
#include "visionlite/enhancer.hpp"
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



    auto contrastImage =
    visionlite::Enhancer::autoContrast(img);

visionlite::BMP::save(
    "assets/output/auto_contrast.bmp",
    contrastImage
);

std::cout
<< "New contrast: "
<< visionlite::Analyzer::contrast(contrastImage)
<< std::endl;
    return 0;
}