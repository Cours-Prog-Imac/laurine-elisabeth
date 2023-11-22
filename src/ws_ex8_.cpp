// Exercice 8 : Rotation 90degree

#include <iostream>
#include <sil/sil.hpp>

int main()
{
    sil::Image logo{"images/logo.png"};
    sil::Image logo_taille_inverse{logo.height(), logo.width()};
    // On passe sur tous les x et tous les y, et on accède au pixel correspondant :
    for (int x{0}; x < logo.width(); x++)
    {
        for (int y{0}; y < logo.height(); y++)
        {
            logo_taille_inverse.pixel(x, y) = logo.pixel((logo.width() - 1) - y, x);
        }
    }
    logo.save("output/logo_ex8_rotation_90_deg.png");
    return 0;
}