// Exercice 10 : Luminosite

#include <iostream>
#include <sil/sil.hpp>

int main()
{
    sil::Image logo{"images/photo.jpg"};
    float coeff{3}; ///metrre un coeff entre 0 et 5 pour une meilleure utilisation
    for (int x{0}; x < logo.width(); x++)
    {
        for (int y{0}; y < logo.height(); y++)
        {
            logo.pixel(x, y).r = pow(logo.pixel(x, y).r, coeff);
            logo.pixel(x, y).g = pow(logo.pixel(x, y).g, coeff);
            logo.pixel(x, y).b = pow(logo.pixel(x, y).b, coeff);
        }
    }
    if (coeff < 1 && coeff > 0)
    {
        logo.save("output/logo_ex10_luminosite_haute.jpg");
    }
    else if (coeff < 5 && coeff > 1)
    {
        logo.save("output/logo_ex10_luminosite_basse.jpg");
    }

    return 0;
}

///////////////////////////////////////////////////////

//luminostie qui sature les pixel deja noir (nb negatif) et qui ne a pas les diminués (comme le ferai les puissance (programme du haut))
// int main()
// {
//     sil::Image logo{"images/logo.png"};
//     int variation{-50}; //entre -100 et 100 pour une meilleure utilisation
//     if (variation < 0)
//     {
//         for (int x{0}; x < logo.width(); x++)
//         {
//             for (int y{0}; y < logo.height(); y++)
//             {
//                 if (logo.pixel(x, y) != glm::vec3{0} || logo.pixel(x, y) != glm::vec3{1})
//                 {
//                     for (int i{0}; i > variation; i--)
//                     {
//                         //filtre noir
//                         logo.pixel(x, y).r -= 0.01; //=glm::vec3{}
//                         logo.pixel(x, y).g -= 0.01;
//                         logo.pixel(x, y).b -= 0.01;
//                     }
//                 }
//             }
//         }
//     }
//     else
//     {
//         for (int x{0}; x < logo.width(); x++)
//         {
//             for (int y{0}; y < logo.height(); y++)
//             {
//                 if (logo.pixel(x, y) != glm::vec3{0} || logo.pixel(x, y) != glm::vec3{1})
//                 {
//                     for (int i{0}; i < variation; i++)
//                     {
//                         //filtre blanc
//                         logo.pixel(x, y).r += 0.01; //=glm::vec3{}
//                         logo.pixel(x, y).g += 0.01;
//                         logo.pixel(x, y).b += 0.01;
//                     }
//                 }
//             }
//         }
//     }
//     logo.save("output/logo_ex10_luminosite_lineaire.png");
//     return 0;
// }
