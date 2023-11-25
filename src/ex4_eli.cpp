#pragma once
#include <sil/sil.hpp>
#include <iostream>

void negatif()
{
    /*EX 4*/
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {
        color = glm::vec3{1 - color.r, 1 - color.g, 1 - color.b};
    }
    image.save("output/ex4.png");
}