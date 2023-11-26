#pragma once
#include <sil/sil.hpp>
#include <iostream>

void miroir()
{
    /*EX 6*/
    sil::Image image{"images/logo.png"};

    // TODO: modifier l'image
    for (int x{0}; x < image.width() / 2; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::swap(image.pixel(x, y), image.pixel(image.width() - x - 1, y));
        }
    }
    image.save("output/ex6.png");
}