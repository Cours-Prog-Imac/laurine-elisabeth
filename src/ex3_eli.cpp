#pragma once
#include <sil/sil.hpp>
#include <iostream>

void noirEtBlanc()
{
    /*EX 3*/
    sil::Image image{"images/logo.png"};

    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {
        float const nuance_de_gris{(color.b + color.g + color.r) / 3};
        color = glm::vec3{nuance_de_gris, nuance_de_gris, nuance_de_gris};
        // color.g = color.b = color.r;
    }
    image.save("output/ex3.png");
}