#include<stdio.h>
#include<math.h>
#include<string.h>
main()
{
FILE *Q;
int roll;
char name[10];
Q = fopen("data.txt","w");
printf("Enter name");
scanf("%s",name);
printf("enter roll no");
scanf("%d",&roll);
fprintf(Q, "%s%d", name,roll);
fclose(Q);

Q = fopen("data.txt","r");
fscanf(Q,"%s%d",name, &roll);
printf("roll no is %d", roll);
printf("name is %s",name);
if (feof(Q) == 0)
{
  printf("end of file not reached");
}
fclose(Q);

}


