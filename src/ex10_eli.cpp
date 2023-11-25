#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <math.h>

void luminosite()
{
    /*EX 10*/
    sil::Image image{"images/photo.jpg"};
    sil::Image image2{"images/photo.jpg"};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            // ASSOMBRISSEMENT
            image2.pixel(x, y).r = pow(image.pixel(x, y).r, 2);
            image2.pixel(x, y).g = pow(image.pixel(x, y).g, 2);
            image2.pixel(x, y).b = pow(image.pixel(x, y).b, 2);

            // ECLAIRCISSEMENT
            image2.pixel(x, y).r = pow(image.pixel(x, y).r, 0.5);
            image2.pixel(x, y).g = pow(image.pixel(x, y).g, 0.5);
            image2.pixel(x, y).b = pow(image.pixel(x, y).b, 0.5);
        }
    }
    image2.save("output/ex10.png");
}