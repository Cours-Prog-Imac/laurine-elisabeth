// Exercice 4
//negatif

// indice : Il faut trouver une formule simple, qui transforme le noir en blanc et
// le blanc en noir (i.e. qui transforme 0 en 1 et 1 en 0).

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
            logo.pixel(x, y).r = 1 - logo.pixel(x, y).r;
            logo.pixel(x, y).g = 1 - logo.pixel(x, y).g;
            logo.pixel(x, y).b = 1 - logo.pixel(x, y).b;
        }
    }
    logo.save("output/logo_ex4_negatif.png");
    return 0;
}