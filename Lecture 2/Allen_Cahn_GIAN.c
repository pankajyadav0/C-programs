#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K (225.0)
#define H (18.0)
#define GAMMA (1.0)

#define deltax (1.0)
#define deltay (1.0)
#define deltat (0.0005)

// #define h (1.4985)
#define h (1.53)
// #define h (0.0)
#define Nx (100)
#define Ny (100)

#define ntimesteps 10000
#define saveT 1000

// #define PLANAR
#define CIRCLE
#define RADIUS (20.0)

double m[Nx][Ny];
double lap[Nx][Ny];

double inv_deltax2;

void compute_laplacian();
void update_m();
void apply_boundary_conditions();
void write2file(long t);
double compute_surface_energy();
void initialize();

void main() {
  long t;
  double surface_energy;
  initialize();
  inv_deltax2 = (1.0/deltax)*(1.0/deltax);
  for (t=0; t < ntimesteps; t++) {
    printf("Timestep=%ld\n",t);
    compute_laplacian();
    update_m();
    apply_boundary_conditions();
    if (t%saveT==0) {
      write2file(t);
    }
  }
  surface_energy = compute_surface_energy();
  printf("Surface_energy=%le\n",surface_energy);
}
void initialize() {
  long x, y;

#ifdef PLANAR
  for(x=0; x < Nx; x++) {
    for(y=0; y < Ny; y++) {
      if (x < Nx*0.5) {
        m[x][y] =  1.0;
      } else {
        m[x][y] = -1.0;
      }
    }
  }
#endif

#ifdef CIRCLE
 for(x=0; x < Nx; x++) {
    for(y=0; y < Ny; y++) {
      if ((x-Nx*0.5)*(x-Nx*0.5) + (y-Ny*0.5)*(y-Ny*0.5) < RADIUS*RADIUS) {
        m[x][y] =  1.0;
      } else {
        m[x][y] = -1.0;
      }
    }
  }
#endif
}
void compute_laplacian() {
  long x, y;
  for(x=1; x < Nx-1; x++) {
    for(y=1; y < Ny-1; y++) {
      lap[x][y]  = m[x+1][y] + m[x-1][y] + m[x][y+1] + m[x][y-1];
      lap[x][y] -= 4.0*m[x][y];
      lap[x][y] *= inv_deltax2;
    }
  }
}
void update_m() {
  long x, y;
  for(x=1; x < Nx-1; x++) {
    for(y=1; y < Ny-1; y++) {
      m[x][y] += deltat*GAMMA*(K*lap[x][y] - H*m[x][y]*(m[x][y]*m[x][y]-1.0) + h);
    }
  }
}
void apply_boundary_conditions() {
  long x, y;
  for(y=1; y < Ny-1; y++) {
    m[0][y]    = m[1][y];
    m[Nx-1][y] = m[Nx-2][y];
  }
  for(x=0; x < Nx; x++) {
    m[x][0]    = m[x][1];
    m[x][Ny-1] = m[x][Ny-2];
  }
}
void write2file(long t) {
  long x, y;
  FILE *fp;
  char filename[10000];
  
  sprintf(filename, "Magnetization_%ld.dat", t);
  fp = fopen(filename,"w");
  for(x=0; x < Nx; x++) {
    for(y=0; y < Ny; y++) {
      fprintf(fp,"%le %le %le\n",x*deltax, y*deltay, m[x][y]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
}
double compute_surface_energy() {
  long x, y;
  double grad_m[2];
  double sum_energy=0.0;
  for(x=1; x < Nx-1; x++) {
    for(y=1; y < Ny-1; y++) {
      grad_m[0]     = (m[x+1][y] - m[x][y])/deltax;
      grad_m[1]     = (m[x][y+1] - m[x][y])/deltay;
      sum_energy   += K*(grad_m[0]*grad_m[0] + grad_m[1]*grad_m[1]); 
    }
  }
  return sum_energy*deltax*deltay;
}

	
