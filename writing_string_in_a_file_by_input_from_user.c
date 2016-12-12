#include<stdio.h>
#include<string.h>
main()
{
FILE *Q;
char *name;
int i;
Q = fopen("pankaj1.txt","w");
 
 printf("enter string\n");

 scanf("%m[a-zA-Z]", &name);
 printf("%s", name);
 while(name !=  NULL){
   fputs(name,Q);
   scanf("%m[a-zA-Z]", &name);
   printf("%s", name);
 }

fclose(Q);
}
