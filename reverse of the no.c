#include<stdio.h>
#include<math.h>
main()
{
int x,y=0,r,i;
printf("Enter the no:\t");
scanf("%d",&x);
 while(x>0)
   {
   r = x%10;
   y = y*10 + r;
   x = x/10;
   }
printf("Reverse of the no is %d\t\n",y);
}
