#include "visionlite/filters.hpp"
#include "visionlite/utils.hpp"
#include "visionlite/transform.hpp"
#include "visionlite/pixel.hpp"
#include "visionlite/convolution.hpp"

namespace visionlite
{


Image Filters::grayscale(
    const Image& image
)
{
    return Transform::applyPixel(
        image,
        [](Pixel p)
        {
            unsigned char gray =
                static_cast<unsigned char>(
                    0.299 * p.r +
                    0.587 * p.g +
                    0.114 * p.b
                );

            return Pixel{
                gray,
                gray,
                gray
            };
        }
    );
}

Image Filters::threshold(
    const Image& image,
    unsigned char value
)
{
    return Transform::applyPixel(
        image,
        [value](Pixel p)
        {
            unsigned char gray =
                static_cast<unsigned char>(
                    0.299 * p.r +
                    0.587 * p.g +
                    0.114 * p.b
                );


            unsigned char result =
                gray >= value
                ? 255
                : 0;


            return Pixel{
                result,
                result,
                result
            };
        }
    );
}

Image Filters::brightness(
    const Image& image,
    int delta
)
{
    return Transform::apply(
        image,
        [delta](unsigned char value)
        {
            return clamp(
                static_cast<int>(value) + delta
            );
        }
    );
}

Image Filters::contrast(
    const Image& image,
    float factor
)
{
    return Transform::apply(
        image,
        [factor](unsigned char value)
        {
            return clamp(
                static_cast<int>(
                    factor * (static_cast<int>(value) - 128)
                    + 128
                )
            );
        }
    );
}

Image Filters::boxBlur(
    const Image& image,
    int size
)
{
    Kernel kernel =
        Kernel::boxBlur(size);


    return Convolution::apply(
        image,
        kernel
    );
}

Image Filters::gaussianBlur(
    const Image& image
)
{
    Kernel kernel =
        Kernel::gaussian3x3();


    return Convolution::apply(
        image,
        kernel
    );
}

Image Filters::sharpen(
    const Image& image
)
{
    Kernel kernel =
        Kernel::sharpen();


    return Convolution::apply(
        image,
        kernel
    );
}

Image Filters::edgeDetectX(
    const Image& image
)
{
    Kernel kernel =
        Kernel::sobelX();


    return Convolution::apply(
        image,
        kernel
    );
}

Image Filters::edgeDetectY(
    const Image& image
)
{
    Kernel kernel =
        Kernel::sobelY();


    return Convolution::apply(
        image,
        kernel
    );
}

}