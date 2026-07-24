#ifndef VISIONLITE_IMAGE_HPP
#define VISIONLITE_IMAGE_HPP

#include <vector>
#include <cstddef>


namespace visionlite
{

class Image
{

private:

    int width;
    int height;
    int channels;

    std::vector<unsigned char> data;


public:

    Image(
        int width,
        int height,
        int channels
    );


    int getWidth() const;

    int getHeight() const;

    int getChannels() const;


    unsigned char& at(
        int x,
        int y,
        int channel
    );


    const unsigned char& at(
        int x,
        int y,
        int channel
    ) const;


    unsigned char* rawData();

    const unsigned char* rawData() const;


    size_t size() const;


};

}

#endif