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


visionlite::Drawing::filledCircle(canvas,300,300,180,red);
visionlite::Drawing::circle(canvas,300,300,180,white);

visionlite::Drawing::filledCircle(canvas,120,120,60,green);
visionlite::Drawing::circle(canvas,120,120,60,white);

visionlite::Drawing::filledCircle(canvas,480,120,40,blue);
visionlite::Drawing::circle(canvas,480,120,40,white);

visionlite::Drawing::filledCircle(canvas,120,480,90,yellow);
visionlite::Drawing::circle(canvas,120,480,90,white);

visionlite::Drawing::filledCircle(canvas,480,480,70,green);
visionlite::Drawing::circle(canvas,480,480,70,white);

visionlite::BMP::save(
    "assets/output/filled_circles.bmp",
    canvas
);
    return 0;
}