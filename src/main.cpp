#include <sil/sil.hpp>
#include <iostream>
#include <cstdlib> // std::rand & std::srand
#include <ctime>   // std::time
#include "random.hpp"
#include <complex>
#include <glm/gtx/matrix_transform_2d.hpp>

/*POUR VORTEX EX 18*/
glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

int main()
{
    /*EX 1

    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
    image.save("output/ex1.png");*/

    /*EX 2
    sil::Image image{"images/logo.png"};
    glm::vec3 x{};
    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {

        x.r = color.r;
        color.r = color.b;
        color.b = x.r;
    }
    image.save("output/ex2.png");
    */

    /*EX 3
    sil::Image image{"images/logo.png"};

    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {
        float const nuance_de_gris{(color.b + color.g + color.r) / 3};
        color = glm::vec3{nuance_de_gris, nuance_de_gris, nuance_de_gris};
        // color.g = color.b = color.r;
    }
    image.save("output/ex3.png");*/

    /*EX 4 PAS BON
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {
        color = glm::vec3{1 - color.r, 1 - color.g, 1 - color.r};
    }
    image.save("output/ex4.png");*/

    /*EX 5
    sil::Image image{300, 200};
    // TODO: modifier l'image
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (x > 0)
            {
                image.pixel(x, y).r = image.pixel(x - 1, y).r + 0.003;
                image.pixel(x, y).g = image.pixel(x - 1, y).g + 0.003;
                image.pixel(x, y).b = image.pixel(x - 1, y).b + 0.003;
                // REVOIR CA image.pixel(x, y) = image.pixel(x / 300, y);
            }
        }
    }
    image.save("output/ex5.png");*/

    /*EX 6
    sil::Image image{"images/logo.png"};

    // TODO: modifier l'image
    for (int x{0}; x < image.width() / 2; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::swap(image.pixel(x, y), image.pixel(image.width() - x - 1, y));
        }
    }
    image.save("output/ex6.png");*/

    /*EX 7
    sil::Image image{"images/logo.png"};

    // TODO: modifier l'image

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y += rand() % 15)
        {
            image.pixel(x, y) = glm::vec3{rand() % 2, rand() % 2, rand() % 2};
        }
    }
    image.save("output/ex7.png");*/

    /* EFFET MATRIX
    sil::Image image{"images/logo.png"};
    for (int x{0}; x < image.width(); x += rand() % 7)
    {
        for (int y{0}; y < image.height(); y += rand() % 5)
        {
            image.pixel(x, y) = glm::vec3{rand() % 2, rand() % 2, rand() % 2};
        }
    }
    image.save("output/matrix.png");*/

    /*EX 9
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width(), image.height()};

    for (int x{0}; x < image.width() - 21; x++)
    {
        for (int y{0}; y < image.height() - 1; y++)
        {
            if (x <= image.width() - 20)
            {
                image2.pixel(x, y).b = image.pixel(x + 20, y).b;
            }
        }
    }
    for (int x{0}; x < image.width() - 1; x++)
    {
        for (int y{0}; y < image.height() - 1; y++)
        {
            image2.pixel(x, y).g = image.pixel(x, y).g;
        }
    }
    for (int x{0}; x < image.width() - 1; x++)
    {
        for (int y{0}; y < image.height() - 1; y++)
        {
            if (x >= 20)
            {
                image2.pixel(x, y).r = image.pixel(x - 20, y).r;
            }
        }
    }

    image2.save("output/ex9.png");*/

    /*EX 8
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.height(), image.width()};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            image2.pixel(x, y) = image.pixel(y, image2.width() - x - 1);
        }
    }
    image2.save("output/ex8.png");*/

    /*EX 9 A FAIRE
    sil::Image image{"images/logo.png"};
    sil::Image image2{"images/logo.png"};

    for (glm::vec3 &color : image2.pixels())
    {
        glm::vec3{color.r, color.g, color.b};
    }
    image2.save("output/test.png");*/

    /*EX 10 A REVOIR
    sil::Image image{"images/photo.jpg"};

    for (glm::vec3 &color : image.pixels())
    {
        color.g -= 0.1;
        color.b -= 0.1;
        color.r -= 0.1;
    }
    image.save("output/ex10.png");*/

    /*EX 14
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width() / 5, image.height() / 5};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {

            image2.pixel(x, y) = image.pixel(x * 5, y * 5);
        }
    }

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int tileX = x % image2.width();
            int tileY = y % image2.height();

            image.pixel(x, y) = image2.pixel(tileX, tileY);
        }

        image.save("output/ex14.png");
    } */

    /*EX 15 CHERCHER PETIT PROBLEME
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width() / 5, image.height() / 5};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {

            image2.pixel(x, y) = image.pixel(x * 5, y * 5);
        }
    }

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int tileX = x % image2.width();
            int tileY = y % image2.height();

            image.pixel(x, y) = image2.pixel(tileX, tileY);
        }
    }
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int vrai_x{x};
            int vrai_y{y};
            if (y >= image2.height() && y < image2.height() * 2)
            {
                vrai_y = image.height() - y - 1;
            }
            if (x >= image2.width() && x < image2.width() * 2)
            {
                vrai_x = image.width() - x - 1;
            }
            std::swap(image.pixel(x, y), image.pixel(vrai_x, vrai_y));
        }
        image.save("output/ex15.png");
    }*/

    /*PIXELS MANQUANTS
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width() - rand() % 2, image.height() - rand() % 2};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y += rand() % 15)
        {
            image2.pixel(x, y) = image.pixel(x, y);
        }
    }
    image2.save("output/pixels_manquants.png");*/

    /*FOURRURE
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width() - rand() % 2, image.height() - rand() % 2};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {

            image2.pixel(x, y) = image.pixel(x + rand() % 2, y + rand() % 2);
        }
    }
    image2.save("output/fourrure.png");*/

    /*EX 16
    sil::Image image{"images/logo.png"};

    for (int i{0}; i < 30; i++)
    {
        int const randomx{random_int(0, image.width() - 1)};
        int const randomy{random_int(0, image.height() - 1)};
        sil::Image minirectangle{(image.width() - randomx) / 5, (image.height() - randomy) / 18};
        for (int x{0}; x < minirectangle.width(); x++)
        {
            for (int y{0}; y < minirectangle.height(); y++)
            {
                minirectangle.pixel(x, y) = image.pixel(randomx + x, randomy + y);
            }
        }

        int const randomxLogo{random_int(0, image.width() - 1)};
        int const randomyLogo{random_int(0, image.height() - 1)};
        for (int x{0}; x < minirectangle.width(); x++)
        {
            for (int y{0}; y < minirectangle.height(); y++)
            {
                if (randomxLogo + x < image.width() && randomyLogo + y < image.height())
                {
                    image.pixel(randomxLogo + x, randomyLogo + y) = minirectangle.pixel(x, y);
                }
            }
        }
    }
    image.save("output/image.png");*/

    /*CIBLE IMAC

    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width(), image.height()};

    glm::vec2 center_of_rotation(image.width() / 2, image.height() / 2);
    float angle{90.};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            image2.pixel(x, y) = image.pixel(x, y);
            glm::vec2 point(x, y);
            float distance{glm::distance(point, center_of_rotation)}; // glm distance est un float
            glm::vec2 new_point{rotated(point, center_of_rotation, angle + x)};

            if (new_point.x > 0 && new_point.x < image.width() && new_point.y > 0 && new_point.y < image.height())
            {
                image.pixel(x, y) = image2.pixel(new_point.x, new_point.y);
            }
        }
    }

    image.save("output/cible_imac.png");*/

    /*IRIS IMAC

    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width(), image.height()};

    glm::vec2 center_of_rotation(image.width() / 2, image.height() / 2);
    float angle{90.};

    for (int x{0}; x < image2.width(); x++)
    {
        for (int y{0}; y < image2.height(); y++)
        {
            image2.pixel(x, y) = image.pixel(x, y);
            glm::vec2 point(x, y);
            float distance{glm::distance(point, center_of_rotation)}; // glm distance est un float
            glm::vec2 new_point{rotated(distance, center_of_rotation, angle + x)};

            if (new_point.x > 0 && new_point.x < image.width() && new_point.y > 0 && new_point.y < image.height())
            {
                image.pixel(x, y) = image2.pixel(new_point.x, new_point.y);
            }
        }
    }

    image.save("output/iris_imac.png");*/

    /*Ex 18

    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width(), image.height()};

    glm::vec2 center_of_rotation(image.width() / 2, image.height() / 2);
    float angle{0};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec2 point(x, y);
            float distance{glm::distance(point, center_of_rotation)}; // glm distance est un float
            glm::vec2 new_point{rotated(point, center_of_rotation, angle + distance * 0.1)};

            if (new_point.x >= 0 && new_point.x <= image.width() && new_point.y >= 0 && new_point.y <= image.height())
            {
                image2.pixel(x, y) = image.pixel(new_point.x, new_point.y);
            }
        }
    }

    image2.save("output/ex18.png");*/

    /*Ex 17*/

    sil::Image image{500, 500};

    for (size_t x = 0; x < image.width(); x++)
    {
        for (size_t y = 0; y < image.height(); y++)
        {
            float x_to_two = x / (float)(image.width()) * 4 - 2;
            float y_to_two = y / (float)(image.height()) * 4 - 2;

            std::complex<float> c{x_to_two, y_to_two};
            std::complex<float> z{0, 0};

            int count{0};

            while (count <= 50)
            {
                z = z * z + c;
                if (std::abs(z) > 2)
                {
                    image.pixel(x, y) = glm::vec3{1.f};
                    break;
                }
                count++;
            }
        }
    }

    // for (float x{0}; x < 2; x += 0.004)
    // {
    //     for (float y{0}; y < 2; y += 0.004)
    //     {
    //         std::complex<float> c{x, y};
    //         std::complex<float> z{0, 0};
    //
    //         while (std::abs(z) <= 2)
    //         {

    //             int int_x{static_cast<int>(x)};
    //             int int_y{static_cast<int>(y)};

    //             image.pixel(abs(int_x) * 250, abs(int_y) * 250).r = 1.f;
    //             image.pixel(abs(int_x) * 250, abs(int_y) * 250).g = 1.f;
    //             image.pixel(abs(int_x) * 250, abs(int_y) * 250).b = 1.f;
    //         }
    // z = z * z + c;

    //     };
    // }
    image.save("output/ex17.png");

    return 0;
}