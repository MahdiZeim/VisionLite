#include "visionlite/morphology.hpp"

namespace
{

int clamp(
    int value,
    int minimum,
    int maximum
)
{
    if (value < minimum)
        return minimum;

    if (value > maximum)
        return maximum;

    return value;
}

visionlite::Image morphologyOperation(
    const visionlite::Image& image,
    int kernelSize,
    bool erosion
)
{
    if (kernelSize < 3 || kernelSize % 2 == 0)
    {
        return image;
    }

    visionlite::Image output(
        image.getWidth(),
        image.getHeight(),
        image.getChannels()
    );

    const int radius = kernelSize / 2;

    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < channels; ++c)
            {
                unsigned char value =
                    erosion ? 255 : 0;

                for (int ky = -radius; ky <= radius; ++ky)
                {
                    for (int kx = -radius; kx <= radius; ++kx)
                    {
                        int nx = clamp(
                            x + kx,
                            0,
                            width - 1
                        );

                        int ny = clamp(
                            y + ky,
                            0,
                            height - 1
                        );

                        unsigned char pixel =
                            image.at(
                                nx,
                                ny,
                                c
                            );

                        if (erosion)
                        {
                            value =
                                std::min(
                                    value,
                                    pixel
                                );
                        }
                        else
                        {
                            value =
                                std::max(
                                    value,
                                    pixel
                                );
                        }
                    }
                }

                output.at(
                    x,
                    y,
                    c
                ) = value;
            }
        }
    }

    return output;
}

}

namespace visionlite
{

Image Morphology::erosion(
    const Image& image,
    int kernelSize
)
{
    return morphologyOperation(
        image,
        kernelSize,
        true
    );
}

Image Morphology::dilation(
    const Image& image,
    int kernelSize
)
{
    return morphologyOperation(
        image,
        kernelSize,
        false
    );
}

Image Morphology::opening(
    const Image& image,
    int kernelSize
)
{
    return dilation(
        erosion(image, kernelSize),
        kernelSize
    );
}

Image Morphology::closing(
    const Image& image,
    int kernelSize
)
{
    return erosion(
        dilation(image, kernelSize),
        kernelSize
    );
}

Image Morphology::gradient(
    const Image& image,
    int kernelSize
)
{
    Image dilated =
        dilation(
            image,
            kernelSize
        );

    Image eroded =
        erosion(
            image,
            kernelSize
        );

    Image output(
        image.getWidth(),
        image.getHeight(),
        image.getChannels()
    );

    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < channels; ++c)
            {
                output.at(
                    x,
                    y,
                    c
                ) =
                    dilated.at(x, y, c)
                    -
                    eroded.at(x, y, c);
            }
        }
    }

    return output;
}

Image Morphology::topHat(
    const Image& image,
    int kernelSize
)
{
    Image opened =
        opening(
            image,
            kernelSize
        );

    Image output(
        image.getWidth(),
        image.getHeight(),
        image.getChannels()
    );

    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < channels; ++c)
            {
                output.at(x, y, c) =
                    image.at(x, y, c)
                    -
                    opened.at(x, y, c);
            }
        }
    }

    return output;
}

Image Morphology::blackHat(
    const Image& image,
    int kernelSize
)
{
    Image closed =
        closing(
            image,
            kernelSize
        );

    Image output(
        image.getWidth(),
        image.getHeight(),
        image.getChannels()
    );

    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < channels; ++c)
            {
                output.at(x, y, c) =
                    closed.at(x, y, c)
                    -
                    image.at(x, y, c);
            }
        }
    }

    return output;
}

}