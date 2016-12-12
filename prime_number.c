#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main()
{
int a,b,i,c;
printf("enter a number\t");
scanf("%d",&a);
b = a/2;
//int c[b-1];
for (i=2;i<=b;i++)
{
  c = a%i;
  if (c == 0)
  {
    printf("Entered number is not a prime number\n");
  }
  exit(0);
}
printf("number is prime number\n");

//int n = sizeof(c)/sizeof(int);
//printf("size of c is %d",n);

}
