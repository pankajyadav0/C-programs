#include<stdio.h>
#include<math.h>
int fact(int);
main()
{ 
 int no,ans;
 printf("Enter a number");
 scanf("%d",&no);
 ans = fact(no);
 printf("factorial is %d\n",ans);
}
int fact(int x)
{
 int f;
 if (x==0)
 {
  return 1;
 }
 else 
 {
  f = x*fact(x-1);  /*Recursion*/
  return f;
 } 
}
