#include<stdio.h>
#include<math.h>
struct student
{
char name[20];
int roll;
}
main()
{
struct student stu;
struct student *p;
p = &stu;
printf("Enter student name:");
scanf("%s",p->name); //(*p).name can also be used
printf("Enter student roll no:");
scanf("%d",&p->roll);  //&(*p).roll
printf("******OUTPUT******");
printf("Student ROll no: %d", (*p).roll);
printf("Student Name: %s",(*p).name);

}
