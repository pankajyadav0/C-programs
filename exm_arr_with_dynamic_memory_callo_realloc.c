#include<stdio.h>
#include<stdlib.h>
main()
{
int i, sum=0, n, *P1, *P2;
printf("Enter the size of array\t");
scanf("%d",&n);
P1 = (int*)calloc(n,sizeof(int)); //create n number of memory blocks of 2 byte size each. malloc creates one memory block of size 
                                   //2byte * n =  2n bytes 
P2 = P1;
//printf("memory allocated is %u",P1);
if (P1 == NULL)
{
printf("Error: Out of Memory");
exit(0);
}
//printf("Enter %d  elements\n",n);
printf("Enter elements\n");
for (i=1;i<=n;i++)
{
scanf("%d",P1);
sum = sum + *P1;
P1++;
}
printf("addition is %d\n",sum);

printf("enter new size of array");
scanf("%d",&n);
P1 = (int *)realloc(P2, n*sizeof(int));
sum = 0;
if(P1==NULL)
{
printf("out of memory");
exit(0);
}
printf("Enter %d elements",n);
for (i=1;i<=n;i++)
{
scanf("%d",P1);
sum = sum + *P1;
P1++;
}
printf("addition is %d\n",sum);
//free(ptr);
}
