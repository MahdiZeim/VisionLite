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


// Bresenham Line Algorithm
// Integer-based rasterization.
// Supports all octants.
void Drawing::line(
    Image& image,
    int x0,
    int y0,
    int x1,
    int y1,
    const Color& color
)
{
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        Drawing::pixel(
            image,
            x0,
            y0,
            color
        );

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void Drawing::rectangle(
    Image& image,
    int x,
    int y,
    int width,
    int height,
    const Color& color
)
{
    if (width <= 0 || height <= 0)
    {
        return;
    }

    const int x2 = x + width - 1;
    const int y2 = y + height - 1;

    // Top
    Drawing::line(
        image,
        x,
        y,
        x2,
        y,
        color
    );

    // Bottom
    Drawing::line(
        image,
        x,
        y2,
        x2,
        y2,
        color
    );

    // Left
    Drawing::line(
        image,
        x,
        y,
        x,
        y2,
        color
    );

    // Right
    Drawing::line(
        image,
        x2,
        y,
        x2,
        y2,
        color
    );
}

}