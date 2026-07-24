#ifndef VISIONLITE_BMP_HPP
#define VISIONLITE_BMP_HPP

#include "image.hpp"
#include <string>


namespace visionlite
{

class BMP
{

public:

    static Image load(
        const std::string& filename
    );


    static bool save(
        const std::string& filename,
        const Image& image
    );

};

}

#endif