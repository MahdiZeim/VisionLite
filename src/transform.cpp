#include "visionlite/transform.hpp"
#include <cmath>

namespace visionlite
{

constexpr double PI = 3.14159265358979323846;

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


Image Transform::resize(
    const Image& image,
    int newWidth,
    int newHeight
)
{
    if (newWidth <= 0 || newHeight <= 0)
    {
        return image;
    }

    const int srcWidth = image.getWidth();
    const int srcHeight = image.getHeight();
    const int channels = image.getChannels();

    Image output(
        newWidth,
        newHeight,
        channels
    );

    const float xScale =
        static_cast<float>(srcWidth) / newWidth;

    const float yScale =
        static_cast<float>(srcHeight) / newHeight;

    for (int y = 0; y < newHeight; ++y)
    {
        int srcY =
            static_cast<int>(y * yScale);

        if (srcY >= srcHeight)
        {
            srcY = srcHeight - 1;
        }

        for (int x = 0; x < newWidth; ++x)
        {
            int srcX =
                static_cast<int>(x * xScale);

            if (srcX >= srcWidth)
            {
                srcX = srcWidth - 1;
            }

            for (int c = 0; c < channels; ++c)
            {
                output.at(x, y, c) =
                    image.at(srcX, srcY, c);
            }
        }
    }

    return output;
}

Image Transform::crop(
    const Image& image,
    int x,
    int y,
    int width,
    int height
)
{
    const int srcWidth = image.getWidth();
    const int srcHeight = image.getHeight();
    const int channels = image.getChannels();

    // Clamp starting position
    if (x < 0)
        x = 0;

    if (y < 0)
        y = 0;

    if (x >= srcWidth || y >= srcHeight)
    {
        return Image(0, 0, channels);
    }

    // Clamp crop size
    if (x + width > srcWidth)
        width = srcWidth - x;

    if (y + height > srcHeight)
        height = srcHeight - y;

    if (width <= 0 || height <= 0)
    {
        return Image(0, 0, channels);
    }

    Image output(
        width,
        height,
        channels
    );

    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            for (int c = 0; c < channels; ++c)
            {
                output.at(col, row, c) =
                    image.at(
                        x + col,
                        y + row,
                        c
                    );
            }
        }
    }

    return output;
}


Image Transform::flipHorizontal(
    const Image& image
)
{
    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    Image output(
        width,
        height,
        channels
    );

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            const int srcX = width - 1 - x;

            for (int c = 0; c < channels; ++c)
            {
                output.at(x, y, c) =
                    image.at(srcX, y, c);
            }
        }
    }

    return output;
}

Image Transform::flipVertical(
    const Image& image
)
{
    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    Image output(
        width,
        height,
        channels
    );

    for (int y = 0; y < height; ++y)
    {
        const int srcY = height - 1 - y;

        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < channels; ++c)
            {
                output.at(x, y, c) =
                    image.at(x, srcY, c);
            }
        }
    }

    return output;
}


Image Transform::rotate(
    const Image& image,
    double angle
)
{
    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    Image output(
        width,
        height,
        channels
    );

    const double radians =
        angle * PI / 180.0;

    const double cosTheta =
        std::cos(radians);

    const double sinTheta =
        std::sin(radians);

    const double centerX =
        (width - 1) / 2.0;

    const double centerY =
        (height - 1) / 2.0;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            const double dx =
                x - centerX;

            const double dy =
                y - centerY;

            const double srcX =
                dx * cosTheta +
                dy * sinTheta +
                centerX;

            const double srcY =
               -dx * sinTheta +
                dy * cosTheta +
                centerY;

            const int nearestX =
                static_cast<int>(
                    std::round(srcX)
                );

            const int nearestY =
                static_cast<int>(
                    std::round(srcY)
                );

            if (
                nearestX >= 0 &&
                nearestX < width &&
                nearestY >= 0 &&
                nearestY < height
            )
            {
                for (int c = 0; c < channels; ++c)
                {
                    output.at(x, y, c) =
                        image.at(
                            nearestX,
                            nearestY,
                            c
                        );
                }
            }
            else
            {
                for (int c = 0; c < channels; ++c)
                {
                    output.at(x, y, c) = 0;
                }
            }
        }
    }

    return output;
}

}