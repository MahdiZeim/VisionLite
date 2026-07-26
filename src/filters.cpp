#include "visionlite/filters.hpp"
#include "visionlite/utils.hpp"
#include "visionlite/transform.hpp"

namespace visionlite
{


Image Filters::grayscale(
    const Image& image
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



            unsigned char gray =
                static_cast<unsigned char>(
                    0.299 * r +
                    0.587 * g +
                    0.114 * b
                );



            result.at(x,y,0)=gray;
            result.at(x,y,1)=gray;
            result.at(x,y,2)=gray;

        }

    }


    return result;

}

Image Filters::brightness(
    const Image& image,
    int delta
)
{
    return Transform::apply(
        image,
        [delta](unsigned char value)
        {
            return clamp(
                static_cast<int>(value) + delta
            );
        }
    );
}

Image Filters::contrast(
    const Image& image,
    float factor
)
{
    return Transform::apply(
        image,
        [factor](unsigned char value)
        {
            return clamp(
                static_cast<int>(
                    factor * (static_cast<int>(value) - 128)
                    + 128
                )
            );
        }
    );
}

}