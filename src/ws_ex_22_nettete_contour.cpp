// EXERCICE 22:
// Netteté, Contours, etc.

// Emboss	Outline	Sharpen
// Une fois que vous avez implémenté l'algo générique de convolution qui prend n'importe quel kernel, vous pourrez trouver sur ce site une liste de kernels pour faire différents effets.

#include <iostream>
#include <cstdlib>
#include <sil/sil.hpp>

int main()
{
    sil::Image logo{"images/logo.png"};
    // On passe sur tous les x et tous les y, et on accède au pixel correspondant :
    for (int x{0}; x < logo.width(); x++)
    {
        for (int y{0}; y < logo.height(); y++)
        {
            std::swap(logo.pixel(x, y).r, logo.pixel(x, y).b);
        }
    }
    logo.save("output/logo_ex2_echange_canaux-swap.png");
    return 0;
}
