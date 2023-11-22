// Exercice 1
// Ne garder que le vert

#include <iostream>
#include <sil/sil.hpp>

int main()
{
    sil::Image logo{"images/logo.png"};
    // On passe sur tous les x et tous les y, et on accède au pixel correspondant :
    for (int x{0}; x < logo.width(); x++)
    {
        for (int y{0}; y < logo.height(); y++)
        {
            logo.pixel(x, y).r = 0.f;
            logo.pixel(x, y).b = 0.f;
        }
    }
    // Ou alors, si on n'a pas besoin de connaître le x et le y, on a une syntaxe plus
    // concise pour itérer sur tous les pixels :
    // for (glm::vec3 &color : logo.pixels())
    // {
    //     color.r = 0.f;
    //     color.b = 0.f;
    // }
    logo.save("output/logo_ex1.png");
    return 0;
}