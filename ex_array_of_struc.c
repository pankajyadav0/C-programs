#include<stdio.h>
#include<string.h>
//typedef
struct student
{
int roll;
char name[10];
}stu[5];
//student;
main()
{
//student stu[5];
int i;
for (i=0;i<5;i++)
	{
	printf("Enter roll no of %d student",i+1);
	scanf("%d",&stu[i].roll);
	printf("Enter name of %d student",i+1);
	scanf("%s",stu[i].name);
	}
}
