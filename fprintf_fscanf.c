#include<stdio.h>
main()
{
FILE *Q;
int roll;
char name[10];
Q = fopen("student.txt","w");
printf("Enter name");
scanf("%s",name);
printf("Enter roll");
scanf("%d",&roll);
fprintf(Q,"%d%s",roll,name);
fclose(Q);
Q = fopen("student.txt","r");
fscanf(Q,"%d%s",&roll,name);
printf("Student roll no is %d",roll);
printf("student name is %s",name);
fclose(Q);
}
