#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(double x)
{
   return x*x -5;
}
double fd(double x)
{ 
  return 2*x;
}
void main()
{
double x1, x0, tol = 1e-6, err = 0;
int i, iter = 0, maxiter;
printf("Make some initial guess, enter maxiter to be performed");
scanf("%lf, %d",&x0, &maxiter);
while (iter<=maxiter)
{
   x1 = x0 - f(x0)/fd(x0); 
   err = fabs(x0 - x1);
   if (err<=tol)
     {   printf("root is %f",x1);
       printf("iterations %d:\t",iter); 
       exit(0);
     }
   x0 = x1;
   iter++;
}
printf("insufficent number of iterations");
printf("iterations %d:\t",iter);
}

