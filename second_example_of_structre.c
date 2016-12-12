#include<stdio.h>
#include<string.h>
struct student 
{
FILE *Q;
int roll;
char name[10];
}
stu1 = {101,"Pankaj"};
main()
{
struct student stu2;
Q = fopen("student","w");
printf("roll no is %d\t\n",stu1.roll);
printf("name is %s\t\n",stu1.name);
printf("2nd student roll\t");
scanf("%d",&stu2.roll);
printf("2nd student name\t");
scanf("%s",stu2.name);
//Q = fopen("student","w");
fprintf(Q,"%d%s",roll,name);
fclose(Q);
}
