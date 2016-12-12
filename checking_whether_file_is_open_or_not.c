#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *Q;
char ch[10], file[10];
printf("enter the file name");
scanf("%s",file);
Q = fopen(file,"r");
if (Q == NULL)
{
	printf("file not exist");
	exit(0);
}
fgets(ch,10,Q);
printf("text is %s",ch);
fclose(Q);
}

