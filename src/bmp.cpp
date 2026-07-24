#include "visionlite/bmp.hpp"

#include <iostream>


namespace visionlite
{


Image BMP::load(
    const std::string& filename
)
{

    std::cout
        << "Loading BMP: "
        << filename
        << std::endl;


    return Image(0,0,3);
}



bool BMP::save(
    const std::string& filename,
    const Image& image
)
{

    std::cout
        << "Saving BMP: "
        << filename
        << std::endl;


    return true;
}


}