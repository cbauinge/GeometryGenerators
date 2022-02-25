#ifndef SPHEROID_H
#define SPHEROID_H

#include <stdlib.h>
#include <math.h>

void GenerateSpheroid(const long long N, const double r, const double zstretch,
    const double centerx, const double centery, const double centerz,
    double * const pointsx, double * const pointsy, double * const pointsz)
{
    const double phi = M_PI * (3.0 - sqrt(5.0));  // golden angle in radians

    for (long long i = 0; i < N; i++)
    {
        const double ytmp = 1.0 - (i / (double)(N - 1)) * 2.0;  // y goes from 1 to -1
        const double radius = sqrt(1.0 - ytmp * ytmp);  // radius at y

        const double theta = phi * i;  // golden angle increment

        pointsx[i] = cos(theta) * radius * r + centerx;
        pointsy[i] = ytmp * r + centery;
        pointsz[i] = zstretch * sin(theta) * radius * r + centerz;
    }
}



#endif