#include<stdio.h>
#include<math.h>
main()
{
 int marks[] = {10,20,30};
 int *pointer[3],i;
 for (i=0;i<3;i++)
  {
   printf("%d\n",marks[i]);
   pointer[i] = &marks[i]; 
  }
 for (i=0;i<3;i++)
   {
    printf(" %d\n",*pointer[i]);
   }
}
