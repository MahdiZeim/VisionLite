#include "visionlite/transform.hpp"


namespace visionlite
{


Image Transform::apply(
    const Image& image,
    std::function<unsigned char(unsigned char)> operation
)
{

    int width =
        image.getWidth();


    int height =
        image.getHeight();


    Image result(
        width,
        height,
        3
    );


    for(int y = 0; y < height; y++)
    {

        for(int x = 0; x < width; x++)
        {

            unsigned char r =
                image.at(x,y,0);


            unsigned char g =
                image.at(x,y,1);


            unsigned char b =
                image.at(x,y,2);



            result.at(x,y,0)
                = operation(r);


            result.at(x,y,1)
                = operation(g);


            result.at(x,y,2)
                = operation(b);

        }

    }


    return result;

}

Image Transform::applyPixel(
    const Image& image,
    std::function<Pixel(Pixel)> operation
)
{
    int width =
        image.getWidth();


    int height =
        image.getHeight();


    Image result(
        width,
        height,
        3
    );


    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {

            Pixel pixel;

            pixel.r =
                image.at(x,y,0);

            pixel.g =
                image.at(x,y,1);

            pixel.b =
                image.at(x,y,2);


            Pixel output =
                operation(pixel);


            result.at(x,y,0)
                = output.r;

            result.at(x,y,1)
                = output.g;

            result.at(x,y,2)
                = output.b;

        }
    }


    return result;
}

}