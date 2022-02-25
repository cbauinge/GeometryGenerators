#include "sphere.h"
#include "spheroid.h"
#include <stdio.h>
#include <stdlib.h>


///returns -1 if everything is alright, otherwise the first id where it is not correct
long long CheckSphere(const long long N, const double r, const double cx, const double cy, const double cz, 
    double const * const x, double const * const y, double const * const z)
{
    const double EPS = 1e-10;
    for (long long i = 0; i < N; i++)
    {
        if (fabs((x[i]-cx)*(x[i]-cx) + (y[i]-cy)*(y[i]-cy) + (z[i]-cz)*(z[i]-cz) - r*r) > EPS)
        {
            return i;
        }
    }

    return -1;
}


int main()
{
    long long N = 100;

    double * x = (double * )malloc(sizeof(double) * N);
    double * y = (double * )malloc(sizeof(double) * N);
    double * z = (double * )malloc(sizeof(double) * N);

    GenerateSphere(N, 1.0, 0.0, 0.0, 0.0, x, y, z);
    long long error = CheckSphere(N, 1.0, 0.0, 0.0, 0.0, x, y, z);
    if (error != -1)
        printf("Invalid Point in sphere 1 at position %lld\n", error);

    GenerateSphere(N, 2.0, 0.0, 0.0, 0.0, x, y, z);
    error = CheckSphere(N, 2.0, 0.0, 0.0, 0.0, x, y, z);
    if (error != -1)
        printf("Invalid Point in sphere 2 at position %lld\n", error);

    GenerateSphere(N, 0.1, 0.0, 0.0, 0.0, x, y, z);
    error = CheckSphere(N, 0.1, 0.0, 0.0, 0.0, x, y, z);
    if (error != -1)
        printf("Invalid Point in sphere 3 at position %lld\n", error);

    GenerateSphere(N, 1.0, 1.0, 0.0, 0.0, x, y, z);
    error = CheckSphere(N, 1.0, 1.0, 0.0, 0.0, x, y, z);
    if (error != -1)
        printf("Invalid Point in sphere 4 at position %lld\n", error);

    GenerateSphere(N, 1.0, 0.0, 1.0, 0.0, x, y, z);
    error = CheckSphere(N, 1.0, 0.0, 1.0, 0.0, x, y, z);
    if (error != -1)
        printf("Invalid Point in sphere 5 at position %lld\n", error);

    GenerateSphere(N, 1.0, 0.0, 0.0, 1.0, x, y, z);
    error = CheckSphere(N, 1.0, 0.0, 0.0, 1.0, x, y, z);
    if (error != -1)
        printf("Invalid Point in sphere 6 at position %lld\n", error);

    GenerateSphere(N, 1.0, 0.0, 0.0, 1.0, x, y, z);
    error = CheckSphere(N, 1.0, 0.0, 0.0, 0.0, x, y, z);
    if (error == -1)
        printf("Test sphere 7 should screw up but doesn't\n");



    free(x);
    free(y);
    free(z);

    return 0;
}


