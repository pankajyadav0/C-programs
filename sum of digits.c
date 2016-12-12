#include<stdio.h>
#include<math.h>
main()
{
int i,a, sum=0;
printf("Enter no\n");
for(i=0;i<10;i++)
{
printf("No is:\t\n");
scanf("%d",&a);
sum = sum + a;
}
printf("sum is %d\t\n",sum);
}
