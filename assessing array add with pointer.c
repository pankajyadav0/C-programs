#include<stdio.h>
#include<math.h>
main()
{
int arr[5], *P, i, total;
printf("enter the elements");
for( i=0; i<5; i++)
{
scanf("%d", &arr[i]);
P=arr;
}
printf("elements are:");
for(i=0; i<5; i++)
{
printf("%d\n",*P);
total = total + *P;
P++;
}
printf("total = %d\n",total);
}

