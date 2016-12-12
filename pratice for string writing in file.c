#include<stdio.h>
#include<math.h>
main()
{

char ch[100] = "Hi This is Pankaj";
FILE *Q;

Q = fopen("string.txt","w");
fputs(ch,Q);

fclose(Q);

Q = fopen("string.txt","r");
fgets(ch,200,	Q);
printf("text is %s",ch);
if (feof == 0)
{
	printf("end of file not reached");
}
if (ferror != 0)
{ 
	printf("Reading....");
}
fclose(Q);


}
