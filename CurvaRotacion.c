#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int N=300;
double bb=0.2497;
double bd=5.16;
double ad=0.3105;
double ah=64.3;

void loadata(double *x, double *y);
void modelo(double *v, double *R, double Mb, double Md, double Mh);
void likelihood(double *yobs, double *ymod, double a);
void likelihood2(double *yobs, double ymod, double a);

float main(void){

        double *Mb_walk, *Md_walk, *Mh_walk, *l_walk;
	double *vdata, *vprime, *rdata, *vmodel, *vmodin;
	double *Mb_prime, *Md_prime, *Mh_prime;
       
        srand (time(NULL));
	Mb_walk=malloc(N*sizeof(double));
	Md_walk=malloc(N*sizeof(double));
        Mh_walk=malloc(N*sizeof(double));
        l_walk=malloc(N*sizeof(double));

        Mb_walk[0]=10.0*drand48();
        Md_walk[0]=10.0*drand48();
	Mh_walk[0]=10.0*drand48();
      
        //y_init = my_model(x_obs, m_walk[0], b_walk[0])
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
        vmodin=malloc(N*sizeof(double));
        
        modelo(vmodin,rdata,Mb_walk[0], Md_walk[0], Mh_walk[0]);
        int chicua;
        likelihood(vdata,vmodin,chicua);
        l_walk[0]=chicua;
        
        
        for(i=0;i<N;i++)
	{
                Mb_prime=malloc(N*sizeof(double));
	        Md_prime=malloc(N*sizeof(double));
                Mh_prime=malloc(N*sizeof(double));
                
                Mb_prime[i]=(Mb_walk[i]+drand48()*(0.05)-0.1);
	        Md_prime[i]=(Md_walk[i]+drand48()*(0.05)-0.1);
                Mh_prime[i]=(Mh_walk[i]+drand48()*(0.05)-0.1);
                
                modelo(vmodel,rdata,Mb_prime[i],Md_prime[i],Mh_prime[i]);
                modelo(vmodin,rdata,Mb_walk[i], Md_walk[i], Mh_walk[i]);
                
      	  	int chi;
                int chiprime;
	
        	likelihood(vdata,vmodin,chi);
                likelihood(vdata,vmodel,chiprime);
        
      		int alfa;
                alfa = (chi/chiprime);
                if(alfa >=1.0)
                {
			Mb_walk[i]=Mb_prime[i];
        		Md_walk[i]=Md_prime[i];
			Mh_walk[i]=Mh_prime[i];
		}
                else
		{
                     double beta =drand48();
                     if(beta<=alfa)
                     {
                        Mb_walk[i]=Mb_prime[i];
        		Md_walk[i]=Md_prime[i];
			Mh_walk[i]=Mh_prime[i];
		     }	
                     else 
                     {
                        Mb_walk[i]=Mb_walk[i];
        		Md_walk[i]=Md_walk[i];
			Mh_walk[i]=Mh_walk[i];
                     }
         	}      
    	 }
	return 0;
}

void modelo(double *v, double *R, double Mb, double Md, double Mh)
{
         int i = 0;
         for(i=1;i<(N-1);i++)
         {
	 	v[i]=(sqrt(Mb)*R[i])/(pow(R[i]*R[i]+bb*bb,3.0/4.0)) + (sqrt(Md)*R[i])/(pow(R[i]*R[i]+(bd+ad)*(bd+ad),3.0/4.0)) + (sqrt(Mh))/(pow(R[i]*R[i]+ah*ah,1.0/4.0));
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

void likelihood2(double *yobs, double ymod, double a)
{
        int suma=0;
	int i = 0;
        double chisq=0;
        for(i=1;i<(N-1);i++)
        {
        	suma+=(yobs[i]-ymod)*(yobs[i]-ymod);
	}
	chisq = (1.0/2.0)*suma;
        a= exp(-chisq);     
}

void loadata(double *x, double *y)
{
	FILE* file = fopen("RadialVelocities.dat", "r");

	char palabra[100];
   	double number;
	int i=0;

	fscanf(file, "%s",palabra);
    	fscanf(file, "%s",palabra);
	
	while(fscanf(file,"%lf\n", &number)==1)
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
