#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <cstdlib> // std::rand & std::srand
#include <ctime>   // std::time
#include <math.h>
#include "random.hpp"
#include <complex>
#include <glm/gtx/matrix_transform_2d.hpp>
#include "headers.hpp"

int main()
{
    vert();
    echangeCanaux();
    noirEtBlanc();
    negatif();
    degrade();
    miroir();
    bruit();
    rotation();
    split();
    luminosite();
    mosaique();
    inverseMosaique();
    glitch();
    fractale();
    vortex();
    convolution();
    triPixels();
    cible_imac();
    pixels_manquants();
    fourrure();
    matrix();
}