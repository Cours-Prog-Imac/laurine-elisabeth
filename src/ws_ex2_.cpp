// Exercise 2
// Échanger les canaux
// Par exemple, échangez le canal rouge et le canal bleu.

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

//Faire ce qui suit n'est pas bon car ca ecraserai le b car r=b(=200) puis b=r(=200) alors que r=100
// logo.pixel(x, y).r = logo.pixel(x, y).b;
// logo.pixel(x, y).b = logo.pixel(x, y).r;
