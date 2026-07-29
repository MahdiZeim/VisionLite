#ifndef VISIONLITE_ANALYZER_HPP
#define VISIONLITE_ANALYZER_HPP

#include "image.hpp"
#include <vector>


namespace visionlite
{

class Analyzer
{

public:

    static std::vector<int> histogram(
        const Image& image
    );


    static float meanIntensity(
        const Image& image
    );


    static unsigned char minIntensity(
        const Image& image
    );


    static unsigned char maxIntensity(
        const Image& image
    );


    static float contrast(
        const Image& image
    );

};

}

#endif