#include<stdio.h>
#include<math.h>
void swap(int *x, int *y)
{
int t;
t = *x;
*x = *y;
*y = t;
}
main()
{
 int a, b;
 printf("enter first no \t");
 scanf("%d",&a);
 printf("enter second no\t");
 scanf("%d",&b);
 
printf("Values before swapping\n");
printf("Value for A is %d \t\n",a);
printf("Value for B is %d \t\n",b);
swap(&a, &b);
printf("Values after swapping\n");
printf("Value for A is %d \t\n",a);
printf("Value for B is %d \t\n",b);

}
//void swap(int *x, int *y)
//{
//int t;
//t = *x;
//*x = *y;
//*y = t;
//}



//a function is first declared then call then define.
//instead defining function after main(), a function can be define in the begining. this is what is 
//shown above.
//careful abt ;
