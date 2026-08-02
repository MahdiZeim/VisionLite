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

};

}