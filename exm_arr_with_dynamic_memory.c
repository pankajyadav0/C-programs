#include<stdio.h>
#include<stdlib.h>
main()
{
int n, *ptr, sum=0, i, *P;
printf("enter the size of array\t");
scanf("%d",&n);
ptr = (int*)malloc(n*sizeof(int));
P = ptr;
printf("Enter the elements in array\t");
for(i=1;i<=n;i++)
{
scanf("%d",ptr);
sum = sum + *ptr;
ptr++;
}
printf("sum of elements of array is %d\n",sum);
printf("Array elements");
for (i=1;i<=n;i++)
{
printf("%d\t\n",*P);
P++;
}
//if (ptr == NULL)
//{
//printf("Error; Out of memory");
//}

}
