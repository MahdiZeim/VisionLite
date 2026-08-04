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


visionlite::Drawing::filledRectangle(canvas, 20, 20, 100, 80, red);

visionlite::Drawing::filledRectangle(canvas, 150, 40, 150, 100, green);

visionlite::Drawing::filledRectangle(canvas, 80, 180, 250, 60, blue);

visionlite::Drawing::filledRectangle(canvas, 320, 250, 120, 180, yellow);

visionlite::Drawing::rectangle(canvas, 15, 15, 110, 90, white);
visionlite::Drawing::rectangle(canvas, 145, 35, 160, 110, white);
visionlite::Drawing::rectangle(canvas, 75, 175, 260, 70, white);
visionlite::Drawing::rectangle(canvas, 315, 245, 130, 190, white);


visionlite::BMP::save(
    "assets/output/filled_rectangles.bmp",
    canvas
);
    return 0;
}