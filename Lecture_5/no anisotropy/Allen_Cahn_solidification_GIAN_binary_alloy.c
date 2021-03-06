#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K (18.0)
#define H (1.0)
#define tau (1.0)
#define ceql (0.9)
#define part (1.0)
#define D (1.0)
#define mu_init (1.0)
#define mu_eq (1.0)

#define deltax (1.0)
#define deltay (1.0)
#define deltat (0.01)

// #define h (1.4985)
// #define h (1.53)
// #define h (0.0)
#define Nx (100)
#define Ny (100)

#define ntimesteps 10000
#define saveT 1000
#define PLANAR
// #define CIRCLE
#define RADIUS (20.0)

double inv_deltax2;

void compute_laplacian(double *, double *);
void update(double *, double *, double *, double *);
void apply_boundary_conditions(double *, double *);
void write2file(double *, double *, long t);
double compute_surface_energy(double *);
void initialize(double *, double *);

void main()
{
    long t;
    double surface_energy;
    inv_deltax2 = (1.0 / deltax) * (1.0 / deltax);

    double *T;
    double *phi;

    double *lap_T;
    double *lap_phi;

    T = (double *) malloc(Nx * Ny * sizeof(double));
    phi = (double *) malloc(Nx * Ny * sizeof(double));
    lap_T = (double *) malloc(Nx * Ny * sizeof(double));
    lap_phi = (double *) malloc(Nx * Ny * sizeof(double));

    initialize(T, phi);
    write2file(T, phi, 0);

    for (t = 1; t < ntimesteps; t++) {
	printf("Timestep=%ld\n", t);
	compute_laplacian(phi, lap_phi);
	compute_laplacian(T, lap_T);
	update(T, phi, lap_T, lap_phi);
	apply_boundary_conditions(T, phi);
	if (t % saveT == 0) {
	    write2file(T, phi, t);
	}
    }
    surface_energy = compute_surface_energy(phi);
    printf("Surface_energy=%le\n", surface_energy);

    free(T);
    free(phi);
    free(lap_T);
    free(lap_phi);
}

void initialize(double *T, double *phi)
{
    long index;
    long x;
#ifdef PLANAR
    for (index = 0; index < Nx * Ny; index++) {
	x = index / Ny;
	if (x < Nx * 0.333) {
	    phi[index] = 1.0;
	} else {
	    phi[index] = 0.0;
	}
    }
    for (index = 0; index < Nx * Ny; index++) {
	T[index] = mu_init;
    }
#endif

#ifdef CIRCLE
//  for(x=0; x < Nx; x++) {
//     for(y=0; y < Ny; y++) {
//       if ((x-Nx*0.5)*(x-Nx*0.5) + (y-Ny*0.5)*(y-Ny*0.5) < RADIUS*RADIUS) {
//         m[x][y] =  1.0;
//       } else {
-//         m[x][y] = -1.0;
//       }
//     }
//   }
#endif
}

void compute_laplacian(double *var, double *lap_var)
{
    long index;
    long east, west;
    long north, south;
    for (index = Ny + 1; index < Ny * (Nx - 1) - 1; index++) {
	east = index + Ny;
	west = index - Ny;
	north = index + 1;
	south = index - 1;

	lap_var[index] = var[east] + var[west];

	if ((north % Ny <= (Ny - 1)) && ((south % Ny) >= 0)) {
	    lap_var[index] += var[north] + var[south];
	}
	lap_var[index] -= 4.0 * var[index];
	lap_var[index] *= inv_deltax2;
    }
}

void update(double *T, double *phi, double *lap_T, double *lap_phi)
{
    long index;
    double delta_phi;
    double delta_T;
    for (index = Ny + 1; index < Ny * (Nx - 1) - 1; index++) {
	delta_phi =
	    K * lap_phi[index] - 2.0 * H * phi[index] * (1.0 - phi[index]) *  (1.0 - 2.0 * phi[index]);
	// delta_phi   += L*((Tm-T[index])/Tm)*6.0*phi[index]*(1.0-phi[index]);
	delta_phi +=  ceql * (part - 1) * (T[index] - mu_eq) * 6.0 * phi[index] * (1.0 - phi[index]);
	delta_phi *= (deltat / tau);

//t is mu in whole code
	delta_T =
	    deltat * (D * lap_T[index]) + T[index] * (1.0 -  part) * 6.0 * phi[index] * (1.0 - phi[index]) * delta_phi;
	phi[index] += delta_phi;
	T[index] += delta_T;
    }
}

void apply_boundary_conditions(double *T, double *phi)
{
    long x, y;
    long index_from;
    long index_to;
    for (y = 0; y < Ny; y++) {
	index_from = 1 * Ny + y;
	index_to = 0 * Ny + y;
	T[index_to] = T[index_from];

	index_from = (Nx - 2) * Ny + y;
	index_to = (Nx - 1) * Ny + y;
	T[index_to] = T[index_from];

	index_from = (Nx - 2) * Ny + y;
	index_to = (Nx - 1) * Ny + y;
	phi[index_to] = phi[index_from];

	index_from = 1 * Ny + y;
	index_to = 0 * Ny + y;
	phi[index_to] = phi[index_from];
    }
    for (x = 0; x < Nx; x++) {
	index_from = x * Ny + 1;
	index_to = x * Ny + 0;
	T[index_to] = T[index_from];

	index_from = x * Ny + (Ny - 2);
	index_to = x * Ny + (Ny - 1);
	T[index_to] = T[index_from];

	index_from = x * Ny + 1;
	index_to = x * Ny + 0;
	phi[index_to] = phi[index_from];

	index_from = x * Ny + (Ny - 2);
	index_to = x * Ny + (Ny - 1);
	phi[index_to] = phi[index_from];
    }
}

void write2file(double *T, double *phi, long t)
{
    long x, y;
    FILE *fp;
    char filename[10000];
    long index;
    double gphi;
    sprintf(filename, "phi_%ld.dat", t);
    fp = fopen(filename, "w");
    for (x = 0; x < Nx; x++) {
	for (y = 0; y < Ny; y++) {
	    index = x * Ny + y;
	    fprintf(fp, "%le %le %le\n", x * deltax, y * deltay,  phi[index]);
	}
	fprintf(fp, "\n");
    }
    fclose(fp);

    sprintf(filename, "diffusion_potential_%ld.dat", t);
    fp = fopen(filename, "w");
    for (x = 0; x < Nx; x++) {
	for (y = 0; y < Ny; y++) {
	    index = x * Ny + y;
	    fprintf(fp, "%le %le %le\n", x * deltax, y * deltay, T[index]);
	}
	fprintf(fp, "\n");
    }
    fclose(fp);
    sprintf(filename, "composition_%ld.dat", t);
    fp = fopen(filename, "w");
    for (x = 0; x < Nx; x++) {
	for (y = 0; y < Ny; y++) {
	    index = x * Ny + y;
	    gphi = phi[index] * phi[index] * (3 - 2 * phi[index]);
	fprintf(fp, "%le %le %le\n", x * deltax, y * deltay, T[index] * (1 + (part - 1) * gphi));}
		fprintf(fp, "\n");}
		fclose(fp);
}

double compute_surface_energy(double *phi) {
		long x, y;
		double grad_m[2];
		double sum_energy = 0.0;
		long index; for (x = 1; x < Nx - 1; x++) {
		for (y = 1; y < Ny - 1; y++) {
		index = x * Ny + y;
		grad_m[0] = (phi[index + Ny] - phi[index]) / deltax;
		grad_m[1] = (phi[index + 1] - phi[index]) / deltay;
		sum_energy += K * (grad_m[0] * grad_m[0] + grad_m[1] * grad_m[1]);}
		}
		return (sum_energy * deltax * deltay);
}
