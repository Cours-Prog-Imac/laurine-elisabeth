// Transfromer les lettre de l'IMAC en couleur
#include <iostream>
#include <cstdlib>
#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image logo{"images/logo.png"};
    // On passe sur tous les x et tous les y, et on accède au pixel correspondant :
    for (int x{0}; x < logo.width(); x++)
    {
        for (int y{0}; y < logo.height(); y++)
        {
            if (logo.pixel(x, y) != glm::vec3{0.0f}) //{0.0f, 0.0f, 0.0f} = {0.0f}
            {
                logo.pixel(x, y) = {random_float(0, 1), random_float(0, 1), random_float(0, 1)};
            }
        }
    }
    logo.save("output/logo_effet_perso_imac_couleur.png");
    return 0;
}
