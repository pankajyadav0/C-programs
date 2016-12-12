#include<stdio.h>
#include<math.h>

int greater(int,int);
void disp(void);
main()
{
 disp();
}

int greater(int x,int y)
{
 if (x>y)
  {
   return x;
  }
 else
 {
   return y;
 }
}
void disp(void)
{
 int a,b,ans;
 printf("enter first number ");
 scanf("%d",&a);
 printf("enter second number ");
 scanf("%d",&b);
 ans = greater(a,b); /*Nesting*/
 printf("Greater is %d\n",ans);
}
                  
 
