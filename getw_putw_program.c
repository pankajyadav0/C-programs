#include<stdio.h>
#include<math.h>
main()
{
int no,i;
char ch;
FILE *Q;
//printf("start");
Q = fopen("integers.txt","w");
//printf("chceck");
for (i=1;i<=50;i++)
{
fprintf(Q,"%d\n",i);
}
//printf("Check1");
fclose(Q);
Q = fopen("integers.txt","r");
//printf("check2");
while(fscanf(Q,"%d\n",&no)!=EOF)
{
	printf("%d\t",no);

}
fclose(Q);
}

