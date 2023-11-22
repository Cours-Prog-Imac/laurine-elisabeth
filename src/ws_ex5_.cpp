//exercice 5 : Dégradé

//INFO :
// Vous pouvez créer une image noire avec :
// sil::Image image{300/*width*/, 200/*height*/};
// puis itérer sur les pixels pour les colorer.

// INDICE 1 : La couleur de chaque pixel doit dépendre de son x uniquement.
// INDICE 2 : Quelle formule permettrait d'avoir 0 (noir) quand x vaut 0 (gauche),
//            et 1 (blanc) quand x vaut image.width() - 1 (droite) ?

#include <iostream>
#include <string>
#include <sil/sil.hpp>
int main()
{
    sil::Image degrade{300 /*width*/, 200 /*height*/};
    for (float x{0.f}; x < degrade.width(); x += 1.0)
    {
        for (float y{0.f}; y < degrade.height(); y += 1.0)
        {
            // degrade.pixel(x, y).r = 0 + 1 / (300 - x);
            // degrade.pixel(x, y).g = 0 + 1 / (300 - x);
            // degrade.pixel(x, y).b = 0 + 1 / (300 - x);
            //IL FAUT VERIFIER QUE LE REUSLTAT EST EN FLOAT POUR NE PAS AVOIR QUE 0 OU 1
            //EST CE QU'ON PEUT FAIRE UN STATIC CAST, CA SERT A RIEN SI?
            degrade.pixel(x, y).r = 0.0 + (1.0 / (x + 1.0));
            degrade.pixel(x, y).g = 0.0 + (1.0 / (x + 1.0));
            degrade.pixel(x, y).b = 0.0 + (1.0 / (x + 1.0));
        }
    }
    degrade.save("output/logo_ex5_degrade.png");
    return 0;
}
