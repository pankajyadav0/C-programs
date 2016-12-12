#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#define J (1.0)
#define h (0.0)
#define T (1.0)
#define saveT (10)
#define nx (50)
#define ny (50)
int spin[nx][ny];
#define MCS (1000)   //Number of Monte Carlo steps

int FLAG[nx][ny];
double compute_delta_E(int x,int y,int neighbour_sum);
double compute_magnetization();
double compute_energy();
void initialize();

void main()
{
  int i=0,neighbour_sum, nsite=0 ;   //i is MCS counter
  double avg_mag, avg_E;
  double rv;
  long index;
  double DELTA_E;
  FILE *fp;
  char filename[10000];
  int x,y; 
  for (x = 0; x < nx; x++)
   {
   for (y=0; y<ny;y++)
     { FLAG[x][y] = 0;}
   }
  initialize();  
  while (i < MCS)
 {
    //choose a random point
    rv = drand48();  // (double)rand()/RANDMAX();
    index = rv*(nx*ny);
    
    x = index / ny;
    y = index % ny;
   
    neighbour_sum = spin[(x+1)%nx][y] + spin[(x-1+nx)%nx][y] + spin[x][(y+1)%ny] + spin[x][(y-1+ny)%ny];    
    DELTA_E = compute_delta_E(x,y,neighbour_sum);
   //    printf("Delta_e is %f\n",DELTA_E);   
   if (DELTA_E < 0.0)
      {  spin[x][y] *= -1.0; }
   else  
      { rv = drand48();
        if (rv < exp(-DELTA_E/T))
           {   spin[x][y] *= -1.0; }
       }
    if (FLAG[x][y]==0)
       {  FLAG[x][y] = 1; 
          nsite++;
       }
     if (nsite == (nx*ny))
       {  i = i+1; 
    printf("MCS=%d\n",i);
    avg_mag =  compute_magnetization();
    avg_E = compute_energy();
    
    if (i%saveT == 0) {   
       sprintf(filename,"spin_state_%d.dat",i);
       fp = fopen(filename,"w");
    
    for (x = 0; x < nx; x++)
       {
           for (y=0; y<ny;y++)
              { fprintf(fp,"%d %d %d\n",x,y,spin[x][y]);}               fprintf(fp,"\n");
       }
   fclose(fp);
    }

  fp = fopen("Magnetization_energy.dat","a");
  fprintf(fp,"%d %f %f\n",i,avg_mag,avg_E);
  fclose(fp);
   
  for (x = 0; x < nx; x++)
     {
   for (y=0; y<ny;y++)
     { FLAG[x][y] = 0;}
   }

   nsite = 0;
      }
}
}
void initialize() {
  int x,y;
  for (x = 0; x < nx; x++)
   {
   for (y=0; y<ny;y++)
     { spin[x][y] = 1;}
   }
}

double compute_delta_E(int x,int y,int neighbour_sum) {
 
  return (-2.0*J*(spin[x][y] * (neighbour_sum + h)));
}

double compute_magnetization(){
  double avg_mag = 0.0;
  int x,y;
  for (x = 0; x < nx; x++)
   {
   for (y=0; y<ny;y++)
     { avg_mag += spin[x][y];}
     
   }

return avg_mag/(nx*ny);
}

double compute_energy(){
  double energy = 0.0;
  int neighbour_sum;
  int x,y;
 for (x = 0; x < nx; x++);
   {
   for (y=0; y<ny;y++);
     {     neighbour_sum = spin[(x+1)%nx][y] + spin[(x-1+nx)%nx][y] + spin[x][(y+1)%ny] + spin[x][(y-1+ny)%ny];
           energy += -J * 0.5 * spin[x][y] * neighbour_sum - h * spin[x][y];
     }
   }
return energy;
}

