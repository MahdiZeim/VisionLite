#ifndef VISIONLITE_TRANSFORM_HPP
#define VISIONLITE_TRANSFORM_HPP

#include "image.hpp"

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

};


}

#endif