#include<stdio.h>
#include<string.h>
main()
{
FILE *p, *q;
char ch;
p=fopen("pankaj.txt","w");
printf("Inpute Line and press EOF");
while((ch=getchar())!=EOF)
{ 
putc(ch,p);
}
fclose(p);
printf("Output1\n");
q=fopen("pankaj.txt","r");
printf("Output2\n");
while((ch=getc(q))!=EOF)
{
printf("%c\n",ch);
}
fclose(q);
}

