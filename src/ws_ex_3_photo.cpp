
#include <iostream>
#include <sil/sil.hpp>
int main()
{
    sil::Image photo{"images/photo.jpg"};
    float luminance{0.f};
    // On passe sur tous les x et tous les y, et on accède au pixel correspondant :
    for (int x{0}; x < photo.width(); x++)
    {
        for (int y{0}; y < photo.height(); y++)
        {
            // Les 4 lignes qui suivent mettent l'image en noir et blanc mais pas en nuance de gris luminance = 0.2126 * (logo.pixel(x, y).r) + (0.7152 * logo.pixel(x, y).g) + (0.0722 * logo.pixel(x, y).b);
            // luminance = 0.2126 * (photo.pixel(x, y).r) + (0.7152 * photo.pixel(x, y).g) + (0.0722 * photo.pixel(x, y).b);
            // luminance = 0.05 * (photo.pixel(x, y).r) + (0.4 * photo.pixel(x, y).g) + (0.005 * photo.pixel(x, y).b);
            luminance = 0.05 * (photo.pixel(x, y).r) + (0.1 * photo.pixel(x, y).g) + (0.005 * photo.pixel(x, y).b);
            photo.pixel(x, y).r = luminance * 12.92;
            photo.pixel(x, y).g = luminance * 12.92;
            photo.pixel(x, y).b = luminance * 12.92;
        }
    }
    photo.save("output/logo_ex3_photo_noir_blanc.jpg");
    return 0;
}