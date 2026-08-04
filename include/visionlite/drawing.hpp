#pragma once

#include "visionlite/image.hpp"
#include "visionlite/color.hpp"

namespace visionlite
{

class Drawing
{
public:

    static void pixel(
        Image& image,
        int x,
        int y,
        const Color& color
    );

    static void line(
    Image& image,
    int x0,
    int y0,
    int x1,
    int y1,
    const Color& color
);

    static void rectangle(
    Image& image,
    int x,
    int y,
    int width,
    int height,
    const Color& color
);

    static void filledRectangle(
    Image& image,
    int x,
    int y,
    int width,
    int height,
    const Color& color
);


};

}