#include "visionlite/image.hpp"


namespace visionlite
{


Image::Image(
    int width,
    int height,
    int channels
)
:
width(width),
height(height),
channels(channels),
data(width * height * channels, 0)
{

}



int Image::getWidth() const
{
    return width;
}



int Image::getHeight() const
{
    return height;
}



int Image::getChannels() const
{
    return channels;
}



unsigned char& Image::at(
    int x,
    int y,
    int channel
)
{

    return data[
        (y * width + x) * channels + channel
    ];

}



const unsigned char& Image::at(
    int x,
    int y,
    int channel
) const
{

    return data[
        (y * width + x) * channels + channel
    ];

}



size_t Image::size() const
{
    return data.size();
}


}