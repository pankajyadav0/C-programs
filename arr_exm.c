#include<stdio.h>
#include<math.h>
main()
{
int i,sum=0, marks[5];
float Average;
int n = sizeof(marks)/sizeof(int);
for (i=0;i<5;i++)
{
printf("Enter %d marks\t\n",i+1);
scanf("%d",&marks[i]);
sum  += marks[i];
}
printf("sum of marks is %d\t\n",sum);
Average = (float)sum/n;
printf("average of marks is %f\t",Average);
}
