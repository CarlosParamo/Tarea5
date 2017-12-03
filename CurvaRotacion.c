#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N=300;
double bb=0.2497;
double bd=5.16;
double ad=0.3105;
double ah=64.3;

void loadata(double *x, double *y);
void modelo(double *v, double *R, double *Mb, double *Md, double *Mh);
void likelihood(double *yobs, double *ymod, double a);

float main(void){

        double *Mb_walk, *Md_walk, *Mh_walk, *vdata, *rdata, *vmodel;
       
	Mb_walk=malloc(N*sizeof(double));
	Md_walk=malloc(N*sizeof(double));
        Mh_walk=malloc(N*sizeof(double));

        Mb_walk[0]=10.0*drand48();
        Md_walk[0]=10.0*drand48();
	Mh_walk[0]=10.0*drand48();
      
        /*y_init = my_model(x_obs, m_walk[0], b_walk[0])*/
        

        vdata=malloc(N*sizeof(double));
        rdata=malloc(N*sizeof(double));
        loadata(rdata,vdata);
        int i;
	for(i=0;i<N;i++)
	{
                printf("%lf ",rdata[i]);
                printf("%lf\n",vdata[i]);
	}
        
	printf("hasta aqui funciona\n");

        vmodel=malloc(N*sizeof(double));
        int chicua;
        
	modelo(vmodel,rdata,Mb_walk, Md_walk, Mh_walk);
        likelihood(vdata,vmodel,chicua);

}

void modelo(double *v, double *R, double *Mb, double *Md, double *Mh)
{
         int i = 0;
         for(i=1;i<(N-1);i++)
         {
		v[i]= (sqrt(Mb[i])*R[i])/(pow(R[i]*R[i]+bb*bb,3.0/4.0)) + (sqrt(Md[i])*R[i])/(pow(R[i]*R[i]+(bd+ad)*(bd+ad),3.0/4.0)) + (sqrt(Mh[i]))/(pow(R[i]*R[i]+ah*ah,1.0/4.0));
	 }
}

void likelihood(double *yobs, double *ymod, double a)
{
        int suma=0;
	int i = 0;
        double chisq=0;
        for(i=1;i<(N-1);i++)
        {
        	suma+=(yobs[i]-ymod[i])*(yobs[i]-ymod[i]);
	}

	chisq = (1.0/2.0)*suma;
        a= exp(-chisq);
        
}

void loadata(double *x, double *y)
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
