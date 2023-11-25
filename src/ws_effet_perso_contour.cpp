//EX PERSO n2 :

// mettre les contour du logo et du texte en couleur
#include <iostream>
#include <cstdlib>
#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image logo{"images/logo.png"};
    for (int x{0}; x < logo.width() - 1; x++)
    {
        for (int y{0}; y < logo.height() - 1; y++)
        {
            if (logo.pixel(x, y) != logo.pixel(x + 1, y) || logo.pixel(x, y) != logo.pixel(x, y + 1) || logo.pixel(x, y) != logo.pixel(x + 1, y + 1)) //on verifie que l'un des pixel a coté est d'une autre couleur
            {
                logo.pixel(x, y) = {0.9, 0.9, 0.0}; //contour jaune
            }
        }
    }
    logo.save("output/logo_effet_perso_contour.png");
    return 0;
}