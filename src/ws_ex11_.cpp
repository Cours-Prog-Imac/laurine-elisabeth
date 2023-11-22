// Exercice 11 : Disque

// INFO
// Vous pouvez créer une image noire avec
// sil::Image image{500/*width*/, 500/*height*/};
// puis itérer sur les pixels pour les colorer.

// INDICE : Quelle est l'équation d'un disque ? Comment peut on s'en
//          servir pour savoir si un pixel est à l'intérieur ou à l'extérieur du disque ?

#include <iostream>
#include <sil/sil.hpp>
#define _USE_MATH_DEFINES
#include <math.h> // pow(10,2)  //pi = M_PI =  3.14159265358979323846
// #define M_PI
// #include <numbers> // std::numbers  // std::numbers::pi ou pi_v

int main()
{
    sil::Image image{500 /*width*/, 500 /*height*/};
    // // float disque{0};
    // //formule disque pi*r^2
    // // disque = (M_PI)*rayon * rayon;

    // for (int x{0}; x < image.width(); x++)
    // {
    //     for (int y{0}; y < image.height(); y++)
    //     {

    //         // cercle placer au centre. Les lignes du dessous pour l'instant programme un rectangle
    //         int heigth_100{image.height() - 100};
    //         int width_100{image.width() - 100};
    //         if (
    //             (y < heigth_100) &&
    //             (y > 100) &&
    //             (x < width_100) &&
    //             (x > 100))
    //         {
    //             // for (int i; i < rayon; i++)
    //             image.pixel(x, y).r = 1;
    //             image.pixel(x, y).g = 1;
    //             image.pixel(x, y).b = 1;
    //         }
    //         else
    //         {
    //             image.pixel(x, y).r = 0;
    //             image.pixel(x, y).g = 0;
    //             image.pixel(x, y).b = 0;
    //         }
    //     }
    // }
    // image.save("output/logo_ex11_carre.png");

    int const rayon{100};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {

            // cercle placer au centre. Les lignes du dessous pour l'instant programme un rectangle
            // int middle{image.width() / 2, image.height() / 2};
            if (pow((x - (image.width() / 2)), 2.0) + pow((y - (image.height() / 2)), 2.0) < pow(rayon, 2))
            {
                // for (int i; i < rayon; i++)
                image.pixel(x, y).r = 1;
                image.pixel(x, y).g = 1;
                image.pixel(x, y).b = 1;
            }
            else
            {
                image.pixel(x, y).r = 0;
                image.pixel(x, y).g = 0;
                image.pixel(x, y).b = 0;
            }
        }
    }
    image.save("output/logo_ex11_disque.png");
    return 0;
}