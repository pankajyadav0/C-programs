#include<stdio.h>
#include<math.h>
main()
{
int n, i, j, k;
//char X[3], k;
//double  m1, X[3], A[20][20], b[3]; float c[20][20];
double  m1, X[3], A[20][20], b[3], c[20][20];
printf("enter the order of matrix A\t");
scanf("%d",&n);

/*printf("Enter the elements of coefficient matrix A\n");
for (i=1; i<=n; i++)
{
  for (j=1; j<=n; j++)
    {
      scanf("%f", &A[i][j]);
    }
}
printf("A matrix is:\n");
for (i=1; i<=n; i++)
{
  for (j=1; j<=n; j++)
    {
    printf(" %g ",A[i][j]);
   }
   printf("\n\n");
     // printf("Elements are [%d][%d]: %f\n",i,j,A[i][j] );
    
}

printf("Enter the coefficient of unknown matrix X\n");
for (k=1; k<=n; k++)
{
  scanf("%s", &X[k-1]);
}
for (i=1; i<=n; i++)
{
  printf("Elements are [%d]: %c\n",i, X[i-1]);
}

printf("enter the coefficient of matrix b\n");
for (i=1; i<=n; i++)
{
  scanf("%f",&b[i]);
}
for (i=1; i<=n; i++)
{
  printf("Elements are [%d]: %f\n",i,b[i]);
}*/

printf("Enter the elemets augmented Matrix C");
for (i=1; i<=n; i++)
{
  for (j=1; j<=n+1; j++)
    {
      scanf("%lf", &c[i][j]);
    }
}
printf("Augmented matrix C is:\n");
for (i=1; i<=n; i++)
{
  for (j=1; j<=n+1; j++)
  {
    printf(" %g ",c[i][j]);
   }
   printf("\n\n");
     // printf("Elements are [%d][%d]: %f\n", i, j, c[i][j] );
}
//Reduction to Upper triangle matrix
for (i=1; i<n; i++)
{
  for (j=i+1; j<=n; j++)
    {
      m1 = c[j][i]/c[i][i];
        for (k=2;k<=n+2;k++)
          {  c[j][k-1] = c[j][k-1] - m1*c[i][k-1];}
    }
}
printf("Upper triangular matrix is:\n");
for (i=1; i<=n; i++)
{
  for (j=1; j<=n+1; j++)
  {
    printf(" %g ",c[i][j]);
   }
   printf("\n\n");
}
//Back substitution
X[n] = (c[n][n+1])/c[n][n];
for (j=n-1;j>=1;j--)
{
    int sum = 0;
    for (i=j;i<n;i++)
    {
        sum = sum + c[j][i+1]*X[i+1];
    }
   X[j] = (c[j][n+1] - sum)/c[j][j];
}
 for (i=1; i<=n; i++)
{

printf("X[%d] is %f\t",i,X[i]);
}

}
