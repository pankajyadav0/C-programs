#include<stdio.h>
#include<math.h>
void add(int , int);
//{
  //printf("enter 1st number %d",x);
  //printf("enter 2nd number %d",y);
  //printf("addition is %d",x+y);
//}

main()
{
int a,b;
void (*ptr)(int,int);
ptr = &add;  // or ptr = add;
printf("Enter first number");
scanf("%d",&a);
printf("Enter 2nd number");
scanf("%d",&b);
ptr(a,b);
}
void add(int x, int y)
{
printf("enter 1st number %d",x);
printf("enter 2nd number %d",y);
printf("addition is %d",x+y);
}
