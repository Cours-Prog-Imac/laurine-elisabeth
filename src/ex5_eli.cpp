#pragma once
#include <sil/sil.hpp>
#include <iostream>

void degrade()
{
    /*EX 5*/
    sil::Image image{300, 200};
    // TODO: modifier l'image
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (x > 0)
            {
                image.pixel(x, y).r = image.pixel(x - 1, y).r + 0.003;
                image.pixel(x, y).g = image.pixel(x - 1, y).g + 0.003;
                image.pixel(x, y).b = image.pixel(x - 1, y).b + 0.003;
            }
        }
    }
    image.save("output/ex5.png");
}