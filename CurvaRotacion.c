#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int N=300;
float bb=0.2497;
float bd=5.16;
float ad=0.3105;
float ah=64.3;

float main(void){
       
	Mb_walk=malloc(N*sizeof(double));
	Md_walk=malloc(N*sizeof(double));
        Mh_walk=malloc(N*sizeof(double)); 

        vdata=malloc(N*sizeof(double));
        rdata=malloc(N*sizeof(double));
        loadata(rdata,vdata);


        vmodel=malloc(N*sizeof(double));
	modelo(vmodel,rdata);

}

void modelo(double *v, double R*)
{
         for(i=1;i<(n_puntos-1);i++)
         {
		v[i]=(sqrt(Mb)*R[i])/(pow(R[i]*R[i]+bb*bb,3.0/4.0))+(sqrt(Md)*R[i])/(pow(R[i]*R[i]+(bd+ad)*(bd+ad),3.0/4.0))+(sqrt(Mh))/(pow(R[i]*R[i]+ah*ah,1.0/4.0))
	}
	
}


void likelihood(double *yobs, double *ymod)
{
        

        for(i=1;i<(n_puntos-1);i++)
        {

           
	}

	chisq = (1.0/2.0)*suma


}

void loadata(double *x, double *y)
{
    int i = 0;
    double number;
    FILE *file = fopen("RadialVelocities.dat", "r");

    while(fscanf(file, "%lf\n", &number)==1)
    {
        
        if(i%2==0 and i<0)
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
