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


Image Enhancer::autoContrast(
    const Image& image
)
{
    unsigned char min =
        Analyzer::minIntensity(image);


    unsigned char max =
        Analyzer::maxIntensity(image);


    Image output(
        image.getWidth(),
        image.getHeight(),
        image.getChannels()
    );

    if(max == min)
    {
    return image;
    }
    
    for(int y = 0; y < image.getHeight(); y++)
    {
        for(int x = 0; x < image.getWidth(); x++)
        {
            for(int c = 0; c < image.getChannels(); c++)
            {

                int value =
                    image.at(x,y,c);


                int newValue =
                    (value - min) * 255
                    /
                    (max - min);


                output.at(x,y,c) =
                    clamp(newValue);

            }
        }
    }


    return output;
}


}