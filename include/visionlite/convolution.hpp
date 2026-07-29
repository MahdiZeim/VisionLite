#ifndef VISIONLITE_CONVOLUTION_HPP
#define VISIONLITE_CONVOLUTION_HPP

#include "image.hpp"
#include "kernel.hpp"

namespace visionlite
{

class Convolution
{
public:

    static Image apply(
        const Image& image,
        const Kernel& kernel
    );

};

}

#endif