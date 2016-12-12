#include<stdio.h>
#include "arguement_nesting_macro_params.c"
#define square(X)  (X)*(X)
#define CUBE(X) (square(X)*(X))
#define AD(a,b,c)     (add(a,b)+c)
main()
{
  #ifdef Multi
      printf("yes multi(a,b) is defined\n");
  #else 
      #define Multi(a,b)  (a*(b))
  #endif
  int mult1, mult2, ad1, ad2, cube, ad3, sq ;
  mult1 = Multi(2,3);
  mult2 = Multi(1+1,2+1);
  ad1 = add(2,3);
  ad2 = add(1+1,2+1);
  cube = CUBE(2+3);
  sq = square(5);
  ad3 = AD(4,5,7);
  printf("multiplication is %d\n",mult1);
  printf("multiplication is %d\n",mult2);
  printf("addition is %d\n",ad1);
  printf("addition is %d\n",ad2);
  printf("addition is %d\n",ad3);
  printf("square is %d\n",sq);
  
  printf("cube is %d\n",cube);
  
}
  
  
