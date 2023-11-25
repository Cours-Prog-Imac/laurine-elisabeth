#pragma once
#include <sil/sil.hpp>
#include <iostream>

void split()
{
    /*EX 9*/
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width(), image.height()};

    for (int x{0}; x < image.width() - 21; x++)
    {
        for (int y{0}; y < image.height() - 1; y++)
        {
            if (x <= image.width() - 20)
            {
                image2.pixel(x, y).b = image.pixel(x + 20, y).b;
            }
        }
    }
    for (int x{0}; x < image.width() - 1; x++)
    {
        for (int y{0}; y < image.height() - 1; y++)
        {
            image2.pixel(x, y).g = image.pixel(x, y).g;
        }
    }
    for (int x{0}; x < image.width() - 1; x++)
    {
        for (int y{0}; y < image.height() - 1; y++)
        {
            if (x >= 20)
            {
                image2.pixel(x, y).r = image.pixel(x - 20, y).r;
            }
        }
    }

    image2.save("output/ex9.png");
}