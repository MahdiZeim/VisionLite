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

visionlite::Color red{255,0,0};
visionlite::Color green{0,255,0};
visionlite::Color blue{0,0,255};
visionlite::Color yellow{255,255,0};
visionlite::Color white{255,255,255};


visionlite::Drawing::line(canvas, 20, 20, 480, 20, red);          // افقی
visionlite::Drawing::line(canvas, 20, 20, 20, 480, green);        // عمودی
visionlite::Drawing::line(canvas, 20, 20, 480, 480, blue);        // قطر اصلی
visionlite::Drawing::line(canvas, 480, 20, 20, 480, yellow);      // قطر مخالف
visionlite::Drawing::line(canvas, 250, 20, 480, 300, white);      // شیب کم
visionlite::Drawing::line(canvas, 20, 250, 150, 480, red);        // شیب زیاد
visionlite::Drawing::line(canvas, 480, 250, 350, 480, green);     // شیب منفی
visionlite::Drawing::line(canvas, 250, 480, 20, 350, blue);       // شیب منفی دیگر


visionlite::BMP::save(
    "assets/output/lines.bmp",
    canvas
);

    return 0;
}