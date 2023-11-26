#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include "random.hpp"
#include <cstdlib> // std::rand & std::srand
#include <ctime>   // std::time

void glitch()
{

    /*EX 16*/
    sil::Image image{"images/logo.png"};

    for (int i{0}; i < 30; i++)
    {
        int const randomx{random_int(0, image.width() - 1)};
        int const randomy{random_int(0, image.height() - 1)};
        sil::Image minirectangle{(image.width() - randomx) / 5, (image.height() - randomy) / 18};
        for (int x{0}; x < minirectangle.width(); x++)
        {
            for (int y{0}; y < minirectangle.height(); y++)
            {
                minirectangle.pixel(x, y) = image.pixel(randomx + x, randomy + y);
            }
        }

        int const randomxLogo{random_int(0, image.width() - 1)};
        int const randomyLogo{random_int(0, image.height() - 1)};
        for (int x{0}; x < minirectangle.width(); x++)
        {
            for (int y{0}; y < minirectangle.height(); y++)
            {
                if (randomxLogo + x < image.width() && randomyLogo + y < image.height())
                {
                    image.pixel(randomxLogo + x, randomyLogo + y) = minirectangle.pixel(x, y);
                }
            }
        }
    }
    image.save("output/ex16.png");
}

void pixels_manquants()
{
    /*PIXELS MANQUANTS*/
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width() - rand() % 2, image.height() - rand() % 2};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y += rand() % 15)
        {
            image2.pixel(x, y) = image.pixel(x, y);
        }
    }
    image2.save("output/pixels_manquants.png");
}

void fourrure()
{

    /*FOURRURE*/
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width() - rand() % 2, image.height() - rand() % 2};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {

            image2.pixel(x, y) = image.pixel(x + rand() % 2, y + rand() % 2);
        }
    }
    image2.save("output/fourrure.png");
}
