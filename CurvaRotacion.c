#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float bb=0.2497;
float bd=5.16;
float ad=0.3105;
float ah=64.3;



void load_data(double *x, double *y)
{
    int i = 0;
    double number;
    FILE *file = fopen("RadialVelocities.dat", "r");

    while(fscanf(file, "%lf\n", &number)==1)
    {
        if(i%2==0)
        {
            x[i/2] = number;
        }
        else
        {
            y[i/2] = number;
        }
        i += 1;
    }
}
