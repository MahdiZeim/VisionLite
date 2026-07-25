#ifndef VISIONLITE_FILTERS_HPP
#define VISIONLITE_FILTERS_HPP

#include "image.hpp"


namespace visionlite
{

class Filters
{

public:

    static Image grayscale(
        const Image& image
    );

    static Image brightness(
    const Image& image,
    int delta
    );
};

}


#endif