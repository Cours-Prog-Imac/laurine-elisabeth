//EX PERSO n2 :

// mettre les contour du logo et du texte en couleur
#include <iostream>
#include <cstdlib>
#include <sil/sil.hpp>

//format png mieux car ne creer pas d'artefacte

int main()
{
    // sil::Image logo{"images/google.png"};
    // sil::Image logo{"images/logo.png"};
    sil::Image logo{"images/Amazon.png"};
    for (int x{0}; x < logo.width() - 1; x++)
    {
        for (int y{0}; y < logo.height() - 1; y++)
        {
            // if (y != 0)
            // {
            if (logo.pixel(x, y) == glm::vec3{1.0f} && logo.pixel(x + 1, y) != glm::vec3{1.0f})
            // if (logo.pixel(x, y) > glm::vec3{0.9f} && logo.pixel(x + 1, y) < glm::vec3{0.9f}) //&& logo.pixel(x, y) != logo.pixel(x, y - 1)
            {
                logo.pixel(x, y) = {0.2, 0.2, 0.2};
                //on fait un degrade de gris
                if (x > 0)
                {
                    logo.pixel(x - 1, y) = {0.4, 0.4, 0.4};
                }
                if (x > 1)
                {
                    logo.pixel(x - 2, y) = {0.6, 0.6, 0.6};
                }
            }
        }
    }
    // logo.save("output/logo_effet_perso_ombre_imac.png");
    // logo.save("output/logo_effet_perso_ombre_google.png");
    logo.save("output/logo_effet_perso_ombre_amazon.png");
    return 0;
}