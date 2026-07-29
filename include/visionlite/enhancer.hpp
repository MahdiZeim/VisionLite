#ifndef VISIONLITE_ENHANCER_HPP
#define VISIONLITE_ENHANCER_HPP

#include "image.hpp"


namespace visionlite
{

class Enhancer
{

public:

    static Image autoBrightness(
        const Image& image
    );

    static Image autoContrast(
    const Image& image
    );

    static Image gammaCorrection(
    const Image& image,
    float gamma
    );

    static Image histogramEqualization(
    const Image& image
    );
};

}

#endif