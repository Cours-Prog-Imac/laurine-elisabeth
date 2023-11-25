#pragma once
#include <sil/sil.hpp>
#include <iostream>

void echangeCanaux()
{
    /*EX 2*/
    sil::Image image{"images/logo.png"};
    glm::vec3 x{};
    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {

        x.r = color.r;
        color.r = color.b;
        color.b = x.r;
    }
    image.save("output/ex2.png");
}