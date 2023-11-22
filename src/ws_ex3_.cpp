// Exercice 3:
// Noir & Blanc
// Luminance = 0,2126 × Rouge + 0,7152 × Vert + 0,0722 × Bleu

#include <iostream>
#include <sil/sil.hpp>
int main()
{
    sil::Image logo{"images/logo.png"};
    float luminance{0.f};
    // On passe sur tous les x et tous les y, et on accède au pixel correspondant :
    for (int x{0}; x < logo.width(); x++)
    {
        for (int y{0}; y < logo.height(); y++)
        {
            // glm::vec3 color = 0.2126 * logo.pixel(x, y).r + 0.7152 * logo.pixel(x, y).g + 0.0722 * logo.pixel(x, y).b;
            // std::swap(logo.pixel(x, y).r, logo.pixel(x, y).b);
            // glm::vec3 color = {0.2126 * (logo.pixel(x, y).r) / 255, (0.7152 * logo.pixel(x, y).g) / 255, (0.0722 * logo.pixel(x, y).b) / 255};
            //Les deux lignes qui suivent mettent l'image en noir et blanc mais pas en nuance de gris
            // float luminance = 0.2126 * (logo.pixel(x, y).r) + (0.7152 * logo.pixel(x, y).g) + (0.0722 * logo.pixel(x, y).b);
            // logo.pixel(x, y).r = logo.pixel(x, y).g = logo.pixel(x, y).b = luminance * 12.92;
            //Les 4 lignes qui suivent mettent l'image en noir et blanc mais pas en nuance de gris
            // luminance = 0.2126 * (logo.pixel(x, y).r) + (0.7152 * logo.pixel(x, y).g) + (0.0722 * logo.pixel(x, y).b);
            // logo.pixel(x, y).r = luminance * 12.92;
            // logo.pixel(x, y).g = luminance * 12.92;
            // logo.pixel(x, y).b = luminance * 12.92;
            //Les trois lignes qui suivent mette en couleur grisées
            // logo.pixel(x, y).r = ((logo.pixel(x, y).r) * 30 + (logo.pixel(x, y).g) * 59 + (logo.pixel(x, y).b) * 11) / 100;
            // logo.pixel(x, y).g = ((logo.pixel(x, y).r) * 30 + (logo.pixel(x, y).g) * 59 + (logo.pixel(x, y).b) * 11) / 100;
            // logo.pixel(x, y).b = ((logo.pixel(x, y).r) * 30 + (logo.pixel(x, y).g) * 59 + (logo.pixel(x, y).b) * 11) / 100;
            logo.pixel(x, y).r = (0.299 * logo.pixel(x, y).r) + (0.587 * logo.pixel(x, y).g) + (0.114 * logo.pixel(x, y).b);
            logo.pixel(x, y).g = (0.299 * logo.pixel(x, y).r) + (0.587 * logo.pixel(x, y).g) + (0.114 * logo.pixel(x, y).b);
            logo.pixel(x, y).b = (0.299 * logo.pixel(x, y).r) + (0.587 * logo.pixel(x, y).g) + (0.114 * logo.pixel(x, y).b);
            // logo.pixel(x, y).r = (0.299 * logo.pixel(x, y).r);
            // logo.pixel(x, y).g = (0.587 * logo.pixel(x, y).g);
            // logo.pixel(x, y).b = (0.114 * logo.pixel(x, y).b);
        }
    }
    logo.save("output/logo_ex3_nuance_gris.png");
    return 0;
}
