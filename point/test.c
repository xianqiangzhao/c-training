#include <stdio.h>
#include <stdlib.h>
/*
a point test
*/
 
int main(){
  
   int a,*p;
   p = &a;
   a = 10;
   printf("%d\n",*p );//10

  int a1 = 200 ,c = 12, d = 13, i, j;
  void **p1[10];
  p1[0] = malloc(sizeof(void *) * 128);
  p1[0][0] =  &a1;
  printf("%d\n",  *(int *) p1[0][0] ); //200
 
  char *s = "this is s!";
  p1[0][1] =  s;
  printf("%s\n", p1[0][1]);

  int a2[2] = {1,2},*p2;
  p2 = a2;
  (*p2)++;
  printf("a2[]\n");
  for (i = 0; i < 2; ++i)
  {
     printf("a2[%d]  = %d\n", i,  a2[i]);

  } //  2 \n  2
  printf("p2\n");
  for (i = 0; i < 2; ++i)
  {
     printf("p2[%d]  = %d\n",i, *(p2+i));

  }// 2 \n  2

  int a3[2][3] = {{1,2,3},{4,5,6}}, (*p3)[3];
  
  printf("a3[][]\n");
  for (i = 0; i < 2; ++i) {
    for (j = 0; j < 3; ++j) {
         printf("a3[%d][%d] = %d\n", i, j, a3[i][j]);
    }
  } // 1 \n 2 \n 3 \n 4 \n 5 \n 6 
  printf("p3\n");
  p3 = a3;
  for (i = 0; i < 2; ++i) {
    for (j = 0; j < 3; ++j) {
         printf("p3[%d][%d] = %d\n", i, j, *(*(p3+i)+j));
    }
  } // 1 \n 2 \n 3 \n 4 \n 5 \n 6 
  
  free(p1[0]);

  return 0;

}
