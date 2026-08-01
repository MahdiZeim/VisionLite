#include "visionlite/bmp.hpp"
#include "visionlite/filters.hpp"
#include "visionlite/kernel.hpp"
#include "visionlite/convolution.hpp"
#include "visionlite/analyzer.hpp"
#include "visionlite/enhancer.hpp"
#include <iostream>
#include "visionlite/morphology.hpp"

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


    auto grayImage =
    visionlite::Filters::grayscale(img);

    auto blackHat = visionlite::Morphology::blackHat(grayImage);

    visionlite::BMP::save(
    "assets/output/blackHat.bmp",
    blackHat
);

   
    return 0;
}