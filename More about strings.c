#include<stdio.h>
#include<string.h>
int main()
{
char name[10];
int i,Z,a=43,b=521,c;
//char str1[] = "This is ";
//char str2[] = "pankaj yadav";
printf("Enter your name\t");
scanf("%s",name);
while(name[i]!='\0')
{
printf("%c is stored at %p\n",name[i],&name[i]);
i++;
}
Z = strlen(name);
printf("Length of string is %d\t\n",Z);
c =a+b;
printf("sum of a and b is %d\t\n",c);
//printf("First string is %s\n",str1);
//printf("Second string is %s\n",str2);
//strcat(str1,str2);
//printf("Final string is %s\n",str1);
}


