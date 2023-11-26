#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void inverseMosaique()
{
    /*EX 15 CHERCHER PETIT PROBLEME*/
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
    }
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int vrai_x{x};
            int vrai_y{y};
            if (y >= image2.height() && y < image2.height() * 2)
            {
                vrai_y = image.height() - y - 1;
            }
            if (x >= image2.width() && x < image2.width() * 2)
            {
                vrai_x = image.width() - x - 1;
            }
            std::swap(image.pixel(x, y), image.pixel(vrai_x, vrai_y));
        }
        image.save("output/ex15.png");
    }
}