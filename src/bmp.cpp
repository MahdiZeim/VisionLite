#include "visionlite/bmp.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdint>

namespace visionlite
{


#pragma pack(push,1)

struct BMPFileHeader
{
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
};


struct BMPInfoHeader
{
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
};

#pragma pack(pop)



Image BMP::load(
    const std::string& filename
)
{

    std::ifstream file(
        filename,
        std::ios::binary
    );


    if(!file)
    {
        throw std::runtime_error(
            "Cannot open BMP file"
        );
    }


    BMPFileHeader fileHeader;

    file.read(
        reinterpret_cast<char*>(&fileHeader),
        sizeof(fileHeader)
    );


    if(fileHeader.type != 0x4D42)
    {
        throw std::runtime_error(
            "Not a BMP file"
        );
    }



    BMPInfoHeader infoHeader;

    file.read(
        reinterpret_cast<char*>(&infoHeader),
        sizeof(infoHeader)
    );



    if(infoHeader.bitCount != 24)
    {
        throw std::runtime_error(
            "Only 24-bit BMP supported"
        );
    }



    int width =
        infoHeader.width;


    int height =
        infoHeader.height;



    Image image(
        width,
        height,
        3
    );



    file.seekg(
        fileHeader.offset,
        std::ios::beg
    );



    int rowSize =
        (width * 3 + 3) & (~3);



    std::vector<unsigned char> row(
        rowSize
    );



    for(int y = height - 1; y >= 0; y--)
    {

        file.read(
            reinterpret_cast<char*>(row.data()),
            rowSize
        );


        for(int x = 0; x < width; x++)
        {

            unsigned char B =
                row[x*3];

            unsigned char G =
                row[x*3+1];

            unsigned char R =
                row[x*3+2];


            image.at(x,y,0)=R;
            image.at(x,y,1)=G;
            image.at(x,y,2)=B;

        }

    }



    std::cout
        << "BMP Loaded: "
        << width
        << "x"
        << height
        << std::endl;



    return image;

}



bool BMP::save(
    const std::string& filename,
    const Image& image
)
{

    std::ofstream file(
        filename,
        std::ios::binary
    );


    if(!file)
    {
        return false;
    }


    int width =
        image.getWidth();


    int height =
        image.getHeight();


    int channels =
        image.getChannels();


    if(channels != 3)
    {
        throw std::runtime_error(
            "Only RGB images supported"
        );
    }



    int rowSize =
        (width * 3 + 3) & (~3);



    int imageSize =
        rowSize * height;



    BMPFileHeader fileHeader{};

    fileHeader.type =
        0x4D42;


    fileHeader.size =
        sizeof(BMPFileHeader)
        +
        sizeof(BMPInfoHeader)
        +
        imageSize;


    fileHeader.offset =
        sizeof(BMPFileHeader)
        +
        sizeof(BMPInfoHeader);



    BMPInfoHeader infoHeader{};


    infoHeader.size =
        sizeof(BMPInfoHeader);


    infoHeader.width =
        width;


    infoHeader.height =
        height;


    infoHeader.planes =
        1;


    infoHeader.bitCount =
        24;


    infoHeader.compression =
        0;


    infoHeader.imageSize =
        imageSize;



    file.write(
        reinterpret_cast<char*>(&fileHeader),
        sizeof(fileHeader)
    );


    file.write(
        reinterpret_cast<char*>(&infoHeader),
        sizeof(infoHeader)
    );



    std::vector<unsigned char> row(
        rowSize,
        0
    );



    for(
        int y = height - 1;
        y >= 0;
        y--
    )
    {

        for(
            int x = 0;
            x < width;
            x++
        )
        {

            int index =
                x * 3;


            row[index]
                =
                image.at(x,y,2); // B


            row[index+1]
                =
                image.at(x,y,1); // G


            row[index+2]
                =
                image.at(x,y,0); // R

        }



        file.write(
            reinterpret_cast<char*>(row.data()),
            rowSize
        );

    }



    std::cout
        << "BMP Saved: "
        << filename
        << std::endl;


    return true;

}

}