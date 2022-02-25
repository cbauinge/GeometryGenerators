#ifndef SPHERE_H
#define SPHERE_H

#include "spheroid.h"


///Generate a discretization of a 3D sphere with radius 'radius' and center
///(centerx, centery, centerz) using N points. 
///The resulting N points (x, y, z) are stored in pointsx, pointsy, pointsz.
///ATTENTION: it is assumed that pointsx, pointsy and pointsz are allocated
///to at least size N outside of this function.
///Note that this is based on calling the GenerateSpheroid function with no stretch (=1.0).
void GenerateSphere(const long long N, const double radius, 
    const double centerx, const double centery, const double centerz,
    double * const pointsx, double * const pointsy, double * const pointsz)
{
    GenerateSpheroid(N, radius, 1.0, centerx, centery, centerz,
        pointsx, pointsy, pointsz);
}



#endif