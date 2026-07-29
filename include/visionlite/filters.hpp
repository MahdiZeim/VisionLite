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
    static Image contrast(
    const Image& image,
    float factor
    );
    
    static Image threshold(
    const Image& image,
    unsigned char value
    );

    static Image boxBlur(
    const Image& image,
    int size = 3
    );


    static Image gaussianBlur(
    const Image& image
    );


    static Image sharpen(
    const Image& image
    );


    static Image edgeDetectX(
    const Image& image
    );


    static Image edgeDetectY(
    const Image& image
    );
};

}


#endif