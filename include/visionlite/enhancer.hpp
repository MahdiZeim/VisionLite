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

};

}

#endif