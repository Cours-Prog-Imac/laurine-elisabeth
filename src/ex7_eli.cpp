#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <cstdlib> // std::rand & std::srand
#include <ctime>   // std::time

void bruit()
{
    /*EX 7*/
    sil::Image image{"images/logo.png"};

    // TODO: modifier l'image

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y += rand() % 15)
        {
            image.pixel(x, y) = glm::vec3{rand() % 2, rand() % 2, rand() % 2};
        }
    }
    image.save("output/ex7.png");
}

void matrix()
{
    /* EFFET MATRIX*/
    sil::Image image{"images/logo.png"};
    for (int x{0}; x < image.width(); x += rand() % 7)
    {
        for (int y{0}; y < image.height(); y += rand() % 5)
        {
            image.pixel(x, y) = glm::vec3{rand() % 2, rand() % 2, rand() % 2};
        }
    }
    image.save("output/matrix.png");
}
