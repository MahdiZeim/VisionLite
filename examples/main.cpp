#include "visionlite/bmp.hpp"
#include "visionlite/image.hpp"
#include "visionlite/filters.hpp"
#include "visionlite/kernel.hpp"
#include "visionlite/convolution.hpp"
#include "visionlite/analyzer.hpp"
#include "visionlite/enhancer.hpp"
#include "visionlite/morphology.hpp"
#include "visionlite/transform.hpp"
#include "visionlite/drawing.hpp"
#include "visionlite/color.hpp"

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
          

visionlite::Image canvas(
    500,
    500,
    3
);

visionlite::Color white{255,255,255};
visionlite::Color red{255,0,0};
visionlite::Color green{0,255,0};
visionlite::Color blue{0,0,255};
visionlite::Color yellow{255,255,0};


visionlite::Drawing::rectangle(
    canvas,
    20,
    20,
    120,
    80,
    white
);

visionlite::Drawing::rectangle(
    canvas,
    180,
    20,
    80,
    120,
    red
);

visionlite::Drawing::rectangle(
    canvas,
    300,
    50,
    150,
    150,
    green
);

visionlite::Drawing::rectangle(
    canvas,
    50,
    200,
    200,
    50,
    blue
);

visionlite::Drawing::rectangle(
    canvas,
    280,
    260,
    180,
    100,
    yellow
);

visionlite::BMP::save(
    "assets/output/rectangles.bmp",
    canvas
);
    return 0;
}