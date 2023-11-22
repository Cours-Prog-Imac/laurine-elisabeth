#include <iostream>
#include <sil/sil.hpp>
#include "random.hpp"

// EX 16 : Glitch

//Commentaire programme :
//dure de reflechir en pensant au deux images
//au debut je prenai toujours la meme partie de l'image 1 donc j'vais des glitch tout noir //voir photo glitch v2 et v3
// au lieu de prendre des parties random de l'image 1
// Je n'avais pas pensé qu'il fallait que les deux parties de programme fonctionne a peu pres de la meme maniere
// => faire deux fois un if suivi de 2 for
//aussi faire attention au dépassement de donnée
//en faisant bien la taille de l'image -1 car on commence à 0

int main()
{
    sil::Image image1{"images/logo.png"};
    int tour{0};
    while (tour < 20)
    {
        int image2RandomSizeX{random_int(10, 20)};
        int image2RandomSizeY{random_int(5, 10)};

        sil::Image image2{image2RandomSizeX, image2RandomSizeY}; //on créer une nouvelle image

        int d = random_int(0, image1.width() - 1);                                            //d = position random x de l'image 1
        int b = random_int(0, image1.height() - 1);                                           //b = position random y de l'image 1
        if ((b + image2.height() < image1.height()) && (d + image2.width() < image1.width())) //on verifie qu'a partir de la position choisi randomment, l'image 2 rentre dans l'image 1 sans depasser
        {
            for (int x{0}; x < image2.width() - 1; x++) //on parcours la taille de l'image2
            {
                for (int y{0}; y < image2.height() - 1; y++)
                {
                    image2.pixel(x, y) = image1.pixel(d + x, b + y); //on prend un petit rectangle de l'image 1 et on copie chaque pixel dans l'image2
                    // image1.pixel(x, y) = {0, 0, 0};  //echanger couleur image1 image 2 mais ici je mets juste une partie d'image 1 en noire
                }
            }
        }

        //  mettre l'image 2 dans l'image 1
        int w{random_int(0, image1.width() - 1)};  //position x random dans l'image1
        int h{random_int(0, image1.height() - 1)}; //position y random dans l'image1

        if ((h + image2.height() < image1.height()) && (w + image2.width() < image1.width())) //on verifie qu'a partir de la position choisi randomment, l'image 2 rentre dans l'image 1 sans depasser
        {
            for (int c{0}; c < image2.width() - 1; c++)
            {
                for (int d{0}; d < image2.height() - 1; d++)
                {
                    image1.pixel(w + c, h + d) = image2.pixel(c, d);
                }
            }
        }
        image1.save("output/logo_ex_16_glitch_v4.png");
        tour += 1;
    }

    return 0;
}
