#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include <glm/gtx/matrix_transform_2d.hpp>

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

void vortex()
{

    /*Ex 18*/

    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width(), image.height()};

    glm::vec2 center_of_rotation(image.width() / 2, image.height() / 2);
    float angle{0};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec2 point(x, y);
            float distance{glm::distance(point, center_of_rotation)};
            glm::vec2 new_point{rotated(point, center_of_rotation, angle + distance * 0.1)};

            if (new_point.x >= 0 && new_point.x <= image.width() && new_point.y >= 0 && new_point.y <= image.height())
            {
                image2.pixel(x, y) = image.pixel(new_point.x, new_point.y);
            }
        }
    }

    image2.save("output/ex18.png");
}

void cible_imac()
{

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

    image.save("output/cible_imac.png");

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
}
