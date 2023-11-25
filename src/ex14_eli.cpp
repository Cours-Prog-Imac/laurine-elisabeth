#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void mosaique()
{
    /*EX 14*/
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width() / 5, image.height() / 5};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {

            image2.pixel(x, y) = image.pixel(x * 5, y * 5);
        }
    }

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int tileX = x % image2.width();
            int tileY = y % image2.height();

            image.pixel(x, y) = image2.pixel(tileX, tileY);
        }

        image.save("output/ex14.png");
    }
}