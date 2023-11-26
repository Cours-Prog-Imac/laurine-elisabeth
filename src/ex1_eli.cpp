
#include <sil/sil.hpp>
#include <iostream>

void vert()
{
    /*EX 1*/
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }

    image.save("output/ex1.png");
}