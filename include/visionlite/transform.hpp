#ifndef VISIONLITE_TRANSFORM_HPP
#define VISIONLITE_TRANSFORM_HPP

#include "image.hpp"
#include "pixel.hpp"

#include <functional>


namespace visionlite
{

class Transform
{

public:

    static Image apply(
        const Image& image,
        std::function<unsigned char(unsigned char)> operation
    );


    static Image applyPixel(
        const Image& image,
        std::function<Pixel(Pixel)> operation
    );

    static Image resize(
        const Image& image,
        int newWidth,
        int newHeight
    );

    static Image crop(
        const Image& image,
        int x,
        int y,
        int width,
        int height
    );

    static Image flipHorizontal(
        const Image& image
    );

    static Image flipVertical(
        const Image& image
    );

    static Image rotate(
        const Image& image,
        double angle
    );

};

}

#endif