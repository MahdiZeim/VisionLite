#include "visionlite/convolution.hpp"

namespace visionlite
{

static int clampCoordinate(
    int value,
    int max
)
{
    if(value < 0)
        return 0;

    if(value >= max)
        return max - 1;

    return value;
}


Image Convolution::apply(
    const Image& image,
    const Kernel& kernel
)
{
    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();


    Image output(
        width,
        height,
        channels
    );


    int kernelWidth = kernel.getWidth();
    int kernelHeight = kernel.getHeight();


    int centerX = kernelWidth / 2;
    int centerY = kernelHeight / 2;


    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {

            for(int c = 0; c < channels; c++)
            {

                float sum = 0.0f;


                for(int ky = 0; ky < kernelHeight; ky++)
                {
                    for(int kx = 0; kx < kernelWidth; kx++)
                    {

                        int imageX =
                            clampCoordinate(
                                x + kx - centerX,
                                width
                            );


                        int imageY =
                            clampCoordinate(
                                y + ky - centerY,
                                height
                            );


                        unsigned char pixel =
                            image.at(
                                imageX,
                                imageY,
                                c
                            );


                        float weight =
                            kernel.at(
                                kx,
                                ky
                            );


                        sum += pixel * weight;

                    }
                }


                if(sum < 0)
                    sum = 0;


                if(sum > 255)
                    sum = 255;


                output.at(
                    x,
                    y,
                    c
                ) = static_cast<unsigned char>(sum);

            }
        }
    }


    return output;
}

}