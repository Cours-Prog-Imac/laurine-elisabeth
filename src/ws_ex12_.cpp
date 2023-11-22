// Exercice 7 : cercle

// En reprenant et modifiant légèrement votre code pour le disque,
// écrivez le code qui donne un cercle. (Son contour aura une épaisseur donnée thickness).

#include <iostream>
#include <sil/sil.hpp>
#include <math.h>
#define M_PI

int main()
{
    //formule perimetre cercle : 2*pi*r
    sil::Image image{500 /*width*/, 500 /*height*/};
    int const rayon{100};
    int epaisseur{0};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {

            // cercle placer au centre. Les lignes du dessous pour l'instant programme un rectangle
            // int middle{image.width() / 2, image.height() / 2};
            if ((pow((x - (image.width() / 2)), 2.0) + pow((y - (image.height() / 2)), 2.0) > pow(rayon - 2, 2)) && (pow((x - (image.width() / 2)), 2.0) + pow((y - (image.height() / 2)), 2.0) < pow(rayon + 2, 2))) //on fait une epaisseur de 4 pixels
            // if ((pow((x - (image.width() / 2)), 2.0) + pow((y - (image.height() / 2)), 2.0) == pow(rayon, 2)))
            {
                // for (int i; i < rayon; i++)
                image.pixel(x, y).r = 1;
                image.pixel(x, y).g = 1;
                image.pixel(x, y).b = 1;
                // epaisseur += 1;
                // if (epaisseur == 10)
                // {
                //     break;
                // }
            }
            else
            {
                image.pixel(x, y).r = 0;
                image.pixel(x, y).g = 0;
                image.pixel(x, y).b = 0;
            }
        }
    }
    image.save("output/logo_ex12_cercle.png");
    return 0;
}