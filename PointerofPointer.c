#include<stdio.h>
#include<math.h>
main()
{
int a=100, *P, **P1;
P = &a;
P1 = &P;
printf("number is %d\n",a);
printf("number is %d\n",*P);
printf("number is %d\n",**P1);
}

