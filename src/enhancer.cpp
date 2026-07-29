#include "visionlite/enhancer.hpp"
#include "visionlite/analyzer.hpp"
#include "visionlite/utils.hpp"

#include <cmath>
#include <iostream>

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


Image Enhancer::gammaCorrection(
    const Image& image,
    float gamma
)
{

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

                unsigned char pixel =
                    image.at(x,y,c);


                float normalized =
                    pixel / 255.0f;


                float corrected =
                    std::pow(
                        normalized,
                        gamma
                    );


                int value =
                    static_cast<int>(
                        corrected * 255.0f
                    );


                output.at(x,y,c) =
                    clamp(value);

            }
        }
    }


    return output;
}

Image Enhancer::histogramEqualization(
    const Image& image
)
{
    if(image.getChannels() != 1)
    {
    std::cerr
        << "Histogram equalization requires grayscale image"
        << std::endl;

    return image;
    }

    int histogram[256] = {0};


    for(int y = 0; y < image.getHeight(); y++)
    {
        for(int x = 0; x < image.getWidth(); x++)
        {
            unsigned char pixel =
                image.at(x, y, 0);

            histogram[pixel]++;
        }
    }


    int cdf[256] = {0};

    cdf[0] = histogram[0];

    for(int i = 1; i < 256; i++)
    {
        cdf[i] =
            cdf[i - 1] + histogram[i];
    }


    int totalPixels =
        image.getWidth()
        *
        image.getHeight();


    int cdfMin = 0;

    for(int i = 0; i < 256; i++)
    {
        if(cdf[i] != 0)
        {
            cdfMin = cdf[i];
            break;
        }
    }

    unsigned char lookup[256];


    for(int i = 0; i < 256; i++)
    {

        int value =
            ((cdf[i] - cdfMin) * 255)
            /
            (totalPixels - cdfMin);


        lookup[i] =
            clamp(value);
    }


    Image output(
        image.getWidth(),
        image.getHeight(),
        image.getChannels()
    );


    for(int y = 0; y < image.getHeight(); y++)
    {
        for(int x = 0; x < image.getWidth(); x++)
        {

            unsigned char pixel =
                image.at(x, y, 0);


            output.at(x, y, 0) =
                lookup[pixel];

        }
    }


    return output;
}

}