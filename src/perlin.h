#ifndef PERLIN_H
#define PERLIN_H

#include <vector>
#include "vec2.h"
#include "defs.h"

class Perlin
{
    std::vector<int> p;

public:
    Perlin();
    Perlin(unsigned int seed);

    // Hmm we could implement a Vector3 but no
    double Noise(double x, double y, double z);

private:
    double Fade(double t);
    double Lerp(double t, double a, double b);
    double Grad(int hash, double x, double y, double z);
};

#endif // PERLIN_H
