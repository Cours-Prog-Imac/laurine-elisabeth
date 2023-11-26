#pragma once
#include <sil/sil.hpp>
#include <iostream>

void rotation()
{
    /*EX 8*/
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.height(), image.width()};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            image2.pixel(x, y) = image.pixel(y, image2.width() - x - 1);
        }
    }
    image2.save("output/ex8.png");
}