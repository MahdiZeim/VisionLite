#ifndef VISIONLITE_KERNEL_HPP
#define VISIONLITE_KERNEL_HPP

#include <vector>

namespace visionlite
{

class Kernel
{

private:

    int width;
    int height;

    std::vector<float> data;


public:

    Kernel(
        int width,
        int height
    );


    int getWidth() const;

    int getHeight() const;


    float& at(
        int x,
        int y
    );


    const float& at(
        int x,
        int y
    ) const;


    float sum() const;


    void normalize();


    static Kernel boxBlur(
        int size
    );


    static Kernel gaussian3x3();


    static Kernel sharpen();


    static Kernel sobelX();


    static Kernel sobelY();

};

}

#endif