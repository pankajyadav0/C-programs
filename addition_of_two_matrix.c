#include<stdio.h>
main()
{
int i,j, a[3][3], b[3][3], c[3][3], A[i][j];
printf("enter first matrix elements\n");
for (i=0; i<3; i++)
{
  for (j=0; j<3; j++)
    {
      scanf("%d", &a[i][j]);
    }
}

for (i=0; i<3; i++)
{
  for (j=0; j<3; j++)
    {
      printf("Elements are [%d][%d]: %d\n",i+1,j+1,a[i][j] );
    }
}

printf("enter second matrix elements\n");
for (i=0; i<3; i++)
{
  for (j=0; j<3; j++)
    {
      scanf("%d", &b[i][j]);
    }
}
for (i=0; i<3; i++)
{
  for (j=0; j<3; j++)
    {
      printf("Elements are [%d][%d]: %d\n",i+1,j+1,b[i][j] );
    }
}

printf("Addition of the matrix is:\n");
for (i=0; i<3; i++)
{
  for (j=0; j<3; j++)
    {
        c[i][j] = a[i][j] + b[i][j];
        printf("Elements of added matrix c are [%d][%d]: %d\n",i+1,j+1,c[i][j] );
    }
}

printf("Transpose of the matrix A is:\n");
for (i=0; i<3; i++)
{
  for (j=0; j<3; j++)
    {
       A[i][j] = a[j][i]; 
       printf("Elements of transposed matrix A are [%d][%d]: %d\n",i+1,j+1, A[i][j] );
    }
}
}
