#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define J (1.0)
#define h (0.0)
#define T (3.0)

#define Nx (100)
#define Ny (100)

#define MCS (1000)  

#define saveT (10)

int spin[Nx][Ny];

int FLAG[Nx][Ny];

double compute_energy();
double compute_magnetization();
double compute_delta_E(int x, int y, int neighbor_sum);
void initialize ();

void main() {
  
  double rv;
  long index;
  int i=0; //MCS counter
  double DELTA_E;
  int nsite=0;
  char filename[10000];
  double avg_E, avg_mag;
  int x, y;
  
  int neighbor_sum;
  FILE *fp;
  
  for (x=0; x < Nx; x++) {
    for (y=0; y < Ny; y++) {
      FLAG[x][y] = 0;
    }
  }
  
  initialize();
  while(i < MCS) {
    //Choose a random point
    rv    = drand48();
    index = rv*(Nx*Ny);
    
    x = index/Ny;
    y = index%Ny;
    
    neighbor_sum = spin[(x+1)%Nx][y] + spin[(x-1 +Nx)%Nx][y] + spin[x][(y+1)%Ny] + spin[x][(y-1+Ny)%Ny];
    
    DELTA_E = compute_delta_E(x,y, neighbor_sum);
    
    if (DELTA_E < 0.0) {
      spin[x][y] *= -1;
    } else {
      rv    = drand48();
      if (rv < e(-DELTA_E/T)) {
        spin[x][y] *= -1;
      }
    }
    if (FLAG[x][y] == 0) {
      FLAG[x][y] = 1;
      nsite++;
    }
    if (nsite == Nx*Ny) {      
      i++;
      printf("MCS=%d\n",i);
      avg_mag = compute_magnetization();
      avg_E   = compute_energy();
      
      if (i%saveT ==0) {
        sprintf(filename,"Spin_state_%d.dat",i);
        fp=fopen(filename, "w");
        
        for (x=0; x < Nx; x++) {
          for (y=0; y < Ny; y++) {
            fprintf(fp,"%d %d %d\n",x, y, spin[x][y]);
          }
          fprintf(fp,"\n");
        }
        fclose(fp);
      }
      
      fp = fopen("Magnetization_energy.dat","a");
      fprintf(fp,"%d %le %le\n", i, avg_mag, avg_E);
      fclose(fp);
      
      for (x=0; x < Nx; x++) {
        for (y=0; y < Ny; y++) {
          FLAG[x][y] = 0;
        }
      }
      nsite = 0;
    }
  }
}
void initialize () {
  int x, y;
  for (x=0; x < Nx; x++) {
    for (y=0; y < Ny; y++) {
      spin[x][y] = 1;
    }
  }
}
double compute_delta_E(int x, int y, int neighbor_sum) {
  return (2.0*J*spin[x][y]*(neighbor_sum + h));
}
double compute_magnetization() {
  double avg_mag = 0.0;
  int x, y;
  for (x=0; x < Nx; x++) {
    for (y=0; y < Ny; y++) {
      avg_mag += spin[x][y];
    }
  }
  return avg_mag/(Nx*Ny);
}
double compute_energy() {
  double energy = 0.0;
  int neighbor_sum;
  int x, y;
  for (x=0; x < Nx; x++) {
    for (y=0; y < Ny; y++) {
      neighbor_sum = spin[(x+1)%Nx][y] + spin[(x-1 +Nx)%Nx][y] + spin[x][(y+1)%Ny] 
    + spin[x][(y-1+Ny)%Ny];
      energy += -J*(0.5)*spin[x][y]*neighbor_sum - h*spin[x][y];
    }
  }
  return energy;
}

