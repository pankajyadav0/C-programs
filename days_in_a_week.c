#include<stdio.h>


/*int a;
printf("enter a number between 0 and 6\n");
scanf("%d",&a);
if (a==0)
{
  printf("Sunday\n");
}
else if (a==1) 
{ 
  printf("Monday\n");
}
else if (a==2)
{
  printf("Tuesday\n");
}
else if (a==3)
{
  printf("Wednesday\n");
}
else if (a==4)
{
  printf("Thrusday\n");
}
else if (a==5)
{
  printf("Friday\n");
}
else if (a==6)
{
  printf("Saturday\n");
}*/
enum days {Mon=2, Tue=4, Wed=6, Thrus=8, Fri=10, Sat=12, Sun=14}
main()
{
int a;
printf("enter a even number between 2 and 14\n");
scanf("%d",&a);
enum days d;
d = a;
if (d==12 || d==14)
{
  printf("its weekend. Sleep\n");
}
else 
{
  printf("its weekday. Go to work\n");
}
}
