#include "visionlite/analyzer.hpp"
#include <iostream>
#include <cmath>

namespace visionlite
{


std::vector<int> Analyzer::histogram(
    const Image& image
)
{
    std::vector<int> histogram(256, 0);


    int width =
        image.getWidth();

    int height =
        image.getHeight();

    int channels =
        image.getChannels();


    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {

            int intensity = 0;


            for(int c = 0; c < channels; c++)
            {
                intensity +=
                    image.at(
                        x,
                        y,
                        c
                    );
            }


            intensity /= channels;


            histogram[intensity]++;

        }
    }


    return histogram;
}



float Analyzer::meanIntensity(
    const Image& image
)
{
    long long sum = 0;


    int width =
        image.getWidth();

    int height =
        image.getHeight();

    int channels =
        image.getChannels();


    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {

            int intensity = 0;


            for(int c = 0; c < channels; c++)
            {
                intensity +=
                    image.at(
                        x,
                        y,
                        c
                    );
            }


            intensity /= channels;


            sum += intensity;

        }
    }


    int totalPixels =
        width * height;


    return static_cast<float>(sum) / totalPixels;
}



unsigned char Analyzer::minIntensity(
    const Image& image
)
{
    unsigned char minimum = 255;


    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();


    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {

            int intensity = 0;


            for(int c = 0; c < channels; c++)
            {
                intensity += image.at(x,y,c);
            }


            intensity /= channels;


            if(intensity < minimum)
            {
                minimum =
                    static_cast<unsigned char>(intensity);
            }
        }
    }


    return minimum;
}


unsigned char Analyzer::maxIntensity(
    const Image& image
)
{
    unsigned char maximum = 0;


    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();


    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {

            int intensity = 0;


            for(int c = 0; c < channels; c++)
            {
                intensity += image.at(x,y,c);
            }


            intensity /= channels;


            if(intensity > maximum)
            {
                maximum =
                    static_cast<unsigned char>(intensity);
            }
        }
    }


    return maximum;
}



float Analyzer::contrast(
    const Image& image
)
{
    float mean =
        meanIntensity(image);


    double variance = 0.0;


    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();


    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {

            int intensity = 0;


            for(int c = 0; c < channels; c++)
            {
                intensity += image.at(x,y,c);
            }


            intensity /= channels;


            double diff =
                intensity - mean;


            variance += diff * diff;

        }
    }


    int totalPixels =
        width * height;


    variance /= totalPixels;


    return static_cast<float>(
        sqrt(variance)
    );
}


}