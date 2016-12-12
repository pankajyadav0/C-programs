#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double f(double x, double y)
{
  return x + y ;

}
main()
{
double x0, y0, x1, y1, xf, k1, k2, k3, k4, h;
int i;
printf("Enter initial x, intial y, and the step size\t");
scanf("%lf,%lf, %lf", &x0, &y0, &h);
printf("Enter x value at which solution of y is required\t");
scanf("%lf",&xf);
printf("Initial x0 is %f,\n Initial y0 is %f and\n step size is %f\n",x0, y0, h);
printf("Value of x at which solution has to be found is %f\n",xf);
double  div = xf/h ;

printf("No of iterations that would be performed is %f\t",div);
for (i=1;i=div;i++)
{
  k1 = f(x0,y0);
  k2 = f((x0 + 0.5*h), (y0 + 0.5*h*k1));
  k3 = f((x0 + 0.5*h), (y0 + 0.5*h*k2));
  k4 = f((x0 + h), (y0 + k3*h));
  y1 = y0 + (1/6)*(k1 + 2*k2 + 2*k3 + k4)*h;
  x1 = x0 + h;
  x0 = x1;
  y0 = y1;
}
printf("Solution of x is %f, solution of y is %f", x1,y1);
}

