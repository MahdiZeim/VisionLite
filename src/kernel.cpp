#include "visionlite/kernel.hpp"

namespace visionlite
{

Kernel::Kernel(
    int width,
    int height
)
    : width(width),
      height(height),
      data(width * height, 0.0f)
{
}

int Kernel::getWidth() const
{
    return width;
}

int Kernel::getHeight() const
{
    return height;
}

float Kernel::sum() const
{
    float total = 0.0f;

    for (float value : data)
    {
        total += value;
    }

    return total;
}

void Kernel::normalize()
{
    float total = sum();

    if (total == 0.0f)
    {
        return;
    }

    for (float& value : data)
    {
        value /= total;
    }
}

Kernel Kernel::boxBlur(int size)
{
    Kernel kernel(size, size);

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            kernel.at(x, y) = 1.0f;
        }
    }

    kernel.normalize();

    return kernel;
}

Kernel Kernel::gaussian3x3()
{
    Kernel kernel(3,3);


    kernel.at(0,0)=1;
    kernel.at(1,0)=2;
    kernel.at(2,0)=1;

    kernel.at(0,1)=2;
    kernel.at(1,1)=4;
    kernel.at(2,1)=2;

    kernel.at(0,2)=1;
    kernel.at(1,2)=2;
    kernel.at(2,2)=1;


    kernel.normalize();


    return kernel;
}

float& Kernel::at(
    int x,
    int y
)
{
    return data[
        y * width + x
    ];
}

const float& Kernel::at(
    int x,
    int y
) const
{
    return data[
        y * width + x
    ];
}

}