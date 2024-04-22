//
// Created by NigelWork on 15/04/2024.
//

#ifndef OPENGLCOURSEWORK_PERLINNOISE_H
#define OPENGLCOURSEWORK_PERLINNOISE_H

#include <random>
#include <vector>
#include <cmath>


class perlinNoise {

    perlinNoise();
    explicit perlinNoise(unsigned int seed);
    double noise(double x, double y, double z);


private:
    unsigned int permutation[512];
    static double fade(double t);
    static double lerp(double t, double a, double b);
    static double grad(int hash, double x, double y, double z);


};


#endif //OPENGLCOURSEWORK_PERLINNOISE_H
