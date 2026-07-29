#include "visionlite/enhancer.hpp"
#include "visionlite/analyzer.hpp"
#include "visionlite/utils.hpp"

namespace visionlite
{


Image Enhancer::autoBrightness(
    const Image& image
)
{
    float mean =
        Analyzer::meanIntensity(image);


    int delta =
        128 - static_cast<int>(mean);


    Image output(
        image.getWidth(),
        image.getHeight(),
        image.getChannels()
    );


    for(int y = 0; y < image.getHeight(); y++)
    {
        for(int x = 0; x < image.getWidth(); x++)
        {
            for(int c = 0; c < image.getChannels(); c++)
            {

                int value =
                    image.at(x,y,c);


                output.at(x,y,c) =
                    clamp(value + delta);

            }
        }
    }


    return output;
}


}