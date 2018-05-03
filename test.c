#include <stdio.h>
#include <stdlib.h>

 
int main(){
  
   int a,*p;
   p = &a;
   a = 10;
   printf("%d\n",*p );

   int a1 = 200 ,c = 12, d = 13;
   void **p1[2];
    p1[1] = malloc(sizeof(void *) * 128);
    p1[1][0] =  &a1;
    printf("%d\n",  *(int *) p1[1][0] );
    //p1 = p1 +1;

   return 0;

}
