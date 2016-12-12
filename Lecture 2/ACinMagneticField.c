#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K (225.0)
#define H (18.0)
//#define GAMMA (1.0)
#define deltax (1.0)
#define deltay (1.0)
#define deltat (0.0005)

#define h (0.0)
#define nx (100)
#define ny (100)

double m[nx][ny];
double lap[nx][ny];

#define PLANAR
//#define CIRCLE
#define RADIUS (20.0)
#define ntimesteps 10000
#define saveT 1000

double inv_deltax2;

void compute_laplacian();
void update_m();
void apply_boundary_conditions();
void write2file(long t);
double compute_surface_energy();
void initialize();

void main(){
long t;
double surface_energy;
initialize();
inv_deltax2 = (1.0/deltax)*(1.0/deltax);
	for (t=0; t<ntimesteps; t++)
	{	 printf("timesteps = %ld\n",t);	
		compute_laplacian();
 		update_m();
		apply_boundary_conditions();
		if (t % saveT == 0){
                 write2file(t);
	        }
	}
        surface_energy = compute_surface_energy();
	printf("Surface_energy = %le\n",surface_energy);
}

void initialize()
        {
        long x,y;
	#ifdef PLANAR
        for(x=0; x<nx; x++)   // 0 to 99
        {
                for (y=0; y<ny; y++)   //0 to 99
                {
                        if (x<nx*0.5)
                        {
                           m[x][y] = 1.0;  //m[0][99] to m[99][99]
                        } 
			else  {
                              m[x][y] = -1.0;
                              }
                }
        }
	#endif

	#ifdef CIRCLE
	for(x=0; x<nx; x++)   // 0 to 99
        {
                for (y=0; y<ny; y++)   //0 to 99
                {	if ((x-nx*0.5)*(x-nx*0.5) + (y-ny*0.5)*(y-ny*0.5)  < RADIUS*RADIUS)
				{ 
					m[x][y] = 1.0;
				}
			else
				{
					m[x][y] = -1.0;
				}
		}
        }
        #endif
	}
void compute_laplacian()
	{
	long x,y;
	for(x=1; x<nx-1; x++)
	{
		for (y=1; y<ny-1; y++)
		{
			lap[x][y] = m[x+1][y] + m[x-1][y] + m[x][y+1] + m[x][y-1];	
			lap[x][y] -= 4.0*m[x][y];
			lap[x][y] *= inv_deltax2;
		}
	}
	}
void update_m()
	{
        long x,y;
        for(x=1; x<nx-1; x++)
        {
                for (y=1; y<ny-1; y++)
                {
                   m[x][y] += deltat*(K*lap[x][y] - H*m[x][y]*(m[x][y]*m[x][y] - 1.0) + h);
                }
        }
        }
void apply_boundary_conditions()
	{
	long x,y;
	for (y=1; y<ny-1; y++)  // 1 to 98
	{
 		m[0][y] = m[1][y];
                m[(nx-1)][y] = m[(nx-2)][y];
	}
	for (x=0; x<nx; x++)
        {
                m[x][0] = m[x][1];
                m[x][(ny-1)] = m[x][(ny-2)];
        }
	}
void write2file(long t)
	{
 	long x,y;
	FILE *fp;
	char filename[100000];

	sprintf(filename,"Magnetization_%ld.dat",t);  
			
	fp = fopen(filename,"w");
	for(x=0;x<nx;x++)
        {
                for (y=0; y<ny; y++)
                {
                   fprintf(fp,"%le %le %le\n",x*deltax, y*deltay, m[x][y]);
                }
	fprintf(fp,"\n");
        }
        fclose(fp);
	}
double compute_surface_energy()	
	{
	long x, y;
	double grad_m[2];
	double sum_energy=0.0;
	for(x=1;x<nx-1; x++)
        {
                for (y=1; y<ny-1; y++)
                {
                  grad_m[0] = (m[x+1][y] - m[x][y])/deltax;
		  grad_m[1] = (m[x][y+1] - m[x][y])/deltay;
		  sum_energy += K*(grad_m[0]*grad_m[0] + grad_m[1]*grad_m[1]);
                }
        }
	return (sum_energy*deltax*deltay);
	}

