#include<stdio.h>
#include<math.h>
void add(int, int);
main()
{
  int a,b,c;
  printf("enter a number\t"); 
  scanf("%d",&a);
  printf("enter second number\t");
  scanf("%d",&b);
 add(a,b);
}
void add(int a, int b)
{
 int d;
 d = a+b;
 printf("Addition is %d",d);
}
