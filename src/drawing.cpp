#include "visionlite/drawing.hpp"

namespace visionlite
{

void Drawing::pixel(
    Image& image,
    int x,
    int y,
    const Color& color
)
{
    if (
        x < 0 ||
        x >= image.getWidth() ||
        y < 0 ||
        y >= image.getHeight()
    )
    {
        return;
    }

    if (image.getChannels() == 1)
    {
        image.at(x, y, 0) =
            static_cast<unsigned char>(
                (
                    static_cast<int>(color.r) +
                    static_cast<int>(color.g) +
                    static_cast<int>(color.b)
                ) / 3
            );
    }
    else
    {
        image.at(x, y, 0) = color.r;
        image.at(x, y, 1) = color.g;
        image.at(x, y, 2) = color.b;
    }
}

}