#include <iostream>

#include "visionlite/image.hpp"



int main()
{

    visionlite::Image img(
        640,
        480,
        3
    );


    std::cout 
        << "Width: "
        << img.getWidth()
        << std::endl;


    std::cout 
        << "Height: "
        << img.getHeight()
        << std::endl;


    std::cout 
        << "Channels: "
        << img.getChannels()
        << std::endl;



    img.at(10,10,0)=255;


    std::cout
        << "Image size: "
        << img.size()
        << " bytes"
        << std::endl;



    return 0;
}