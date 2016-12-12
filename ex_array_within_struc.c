#include<stdio.h>
#include<string.h>
#include<math.h>
struct student
{
int roll;
int marks[5];
char name[10];
}stu;
main()
{
int i, sum=0;
printf("Roll no is\t");
scanf("%d",&stu.roll);
printf("Name is\t");
scanf("%s",stu.name);
printf("Marks\t");
for(i=0;i<5;i++)
{
printf("Mark of %d subject is\t",i+1);
scanf("%d",&stu.marks[i]);
sum = sum + stu.marks[i];
}
printf("sum is %d\t",sum);
}
