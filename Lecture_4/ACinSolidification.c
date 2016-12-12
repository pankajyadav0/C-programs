#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K (18.0)
#define H (1.0)
#define tau (1.0)
#define L (1.0)
#define Tm (1.0)
#define D (1.0)
#define c (1.0)
#define tinit (0.1)

#define deltax (1.0)
#define deltay (1.0)
#define deltat (0.05)

#define nx (100)
#define ny (100)

double T[nx][ny];
double phi[nx][ny];
double lap_T[nx][ny];
double lap_phi[nx][ny];

#define PLANAR
//#define CIRCLE
#define RADIUS (20.0)
#define ntimesteps 10000
#define saveT 1000

double inv_deltax2;

void initialize(double *, double *);
void compute_laplacian(double *, double *);
void update(double *, double *, double *, double *);
void apply_boundary_conditions(double *, double *);
void write2file(double *, double *, long t);
double compute_surface_energy(double *);

void main()
{
    long t;
    double surface_energy;

    inv_deltax2 = (1.0 / deltax) * (1.0 / deltax);
    double *T;
    double *phi;
    double *lap_T;
    double *lap_phi;

    T = (double *) malloc(nx * ny * sizeof(double));
    phi = (double *) malloc(nx * ny * sizeof(double));
    lap_T = (double *) malloc(nx * ny * sizeof(double));
    lap_phi = (double *) malloc(nx * ny * sizeof(double));

    initialize(T, phi);

    for (t = 0; t < ntimesteps; t++) {
	printf("timesteps = %ld\n", t);
	compute_laplacian(phi, lap_phi);
	compute_laplacian(T, lap_T);
	update(T, phi, lap_T, lap_phi);
	apply_boundary_conditions(T, phi);
	if (t % saveT == 0) {
	    write2file(T, phi, t);
	}
    }
    surface_energy = compute_surface_energy(phi);
    printf("Surface_energy = %le\n", surface_energy);
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
    for (index = 0; index < nx; index++)	// 0 to 99
    {
	x = index / ny;
	{
	    if (x < nx * 0.333) {
		phi[index] = 1.0;	//m[0][99] to m[99][99]
	    } else {
		phi[index] = -1.0;
	    }
	}
    }

    for (index = 0; index < nx; index++)	// 0 to 99
    {
	T[index] = tinit;
    }

#endif

    /*#ifdef CIRCLE
       for(x=0; x<nx; x++)   // 0 to 99
       {
       for (y=0; y<ny; y++)   //0 to 99
       {    if ((x-nx*0.5)*(x-nx*0.5) + (y-ny*0.5)*(y-ny*0.5)  < RADIUS*RADIUS)
       { 
       m[x][y] = 1.0;
       }
       else
       {
       m[x][y] = -1.0;
       }
       }
       }
       #endif */
}

void compute_laplacian(double *var, double *lap_var)
{
    long index;
    long E, W, N, S;
    for (index = ny + 1; index < ny * (nx - 1); index++) {
	E = index + ny;
	W = index - ny;
	N = index + 1;
	S = index - 1;

	lap_var[index] = var[E] + var[W];
	if (((N % ny) <= (ny - 1)) && (S % ny >= 0)) {lap_var[index] += var[N] + var[S];
	}
	lap_var[index] -= 4 * var[index];
	lap_var[index] *= inv_deltax2;

    }
}

void update(double *T, double *phi, double *lap_T, double *lap_phi)
{
    long index;
    double delta_phi, delta_T;
    for (index = ny + 1; index < ny * (nx - 1); index++) {
	delta_phi = (K * lap_phi[index] - 2 * H * phi[index] * (1 - phi[index]) * (1 - 2 * phi[index]));
	delta_phi += L * ((Tm - T[index]) / Tm) * 6 * phi[index] * (1 - phi[index]);
	delta_phi += (deltat / tau);

	delta_T = deltat * (D * lap_T[index]) + (L / c) * 6 * phi[index] * (1 - phi[index])* delta_phi;
	phi[index] += delta_phi;
	T[index] += delta_T;
    }
}

void apply_boundary_conditions(double *T, double *phi)
{
    long x, y;
    long index_from;
    long index_to;
    for (y = 0; y < ny; y++)	// 1 to 98
    {
	//phi periodic and T is no-flux
	index_from = 1 * ny + y;
	index_to = 0 * ny + y;
	T[index_to] = T[index_from];

	index_from = (nx - 2) * ny + y;
	index_to = (nx - 1) * ny + y;
	T[index_to] = T[index_from];

	index_from = (nx - 2) * ny + y;
	index_to = 0 * ny + y;
	phi[index_to] = phi[index_from];

	index_from = 1 * ny + y;
	index_to = (nx - 1) * ny + y;
	phi[index_to] = phi[index_from];

    }
    for (x = 0; x < nx; x++) {
	index_from = x * ny + 1;
	index_to = x * ny + 0;
	T[index_to] = T[index_from];

	index_from = x * ny + (nx - 2);
	index_to = x * ny + (nx - 1);
	T[index_to] = T[index_from];

	index_from = x * ny + (nx - 2);
	index_to = x * ny + 0;
	phi[index_to] = phi[index_from];

	index_from = x * ny + 1;
	index_to = x * ny + (ny - 1);
	phi[index_to] = phi[index_from];


    }
}

void write2file(double *T, double *phi, long t)
{
    long x, y;
    FILE *fp;
    char filename[100000];
    long index;
    sprintf(filename, "Phi_%ld.dat", t);

    fp = fopen(filename, "w");
    for (x = 0; x < nx; x++) {
	for (y = 0; y < ny; y++) {
	    index = x * ny + y;
	    fprintf(fp, "%le %le %le\n", x * deltax, y * deltay, phi[index]);
	}
	fprintf(fp, "\n");
    }
    fclose(fp);

    sprintf(filename, "Temperature=_%ld.dat", t);

    fp = fopen(filename, "w");
    for (x = 0; x < nx; x++) {
	for (y = 0; y < ny; y++) {
	    index = x * ny + y;
	    fprintf(fp, "%le %le %le\n", x * deltax, y * deltay, T[index]);
	}
	fprintf(fp, "\n");
    }
    fclose(fp);

}


double compute_surface_energy(double *phi)
{
    long x, y;
    double grad_m[2];
    double sum_energy = 0.0;
    long index;
    for (x = 1; x < nx - 1; x++) {
	for (y = 1; y < ny - 1; y++) {
	    index = x * ny + y;
	    grad_m[0] = (phi[index + ny] - phi[index]) / deltax;
	    grad_m[1] = (phi[index + 1] - phi[index]) / deltay;
	    sum_energy += K * (grad_m[0] * grad_m[0] + grad_m[1] * grad_m[1]);
	}
    }
    return (sum_energy * deltax * deltay);
}
