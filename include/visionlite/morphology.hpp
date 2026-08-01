#ifndef VISIONLITE_MORPHOLOGY_HPP
#define VISIONLITE_MORPHOLOGY_HPP

#include "image.hpp"

namespace visionlite
{

class Morphology
{

public:

    static Image erosion(
        const Image& image,
        int kernelSize = 3
    );

    static Image dilation(
        const Image& image,
        int kernelSize = 3
    );

    static Image opening(
        const Image& image,
        int kernelSize = 3
    );

    static Image closing(
        const Image& image,
        int kernelSize = 3
    );

    static Image gradient(
        const Image& image,
        int kernelSize = 3
    );

    static Image topHat(
        const Image& image,
        int kernelSize = 3
    );

    static Image blackHat(
        const Image& image,
        int kernelSize = 3
    );

};

}

#endif