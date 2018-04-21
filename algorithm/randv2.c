#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
/*

排序的改进版
*/

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
 int
 main(int argc, char *argv[])
 {
    int max =  atoi(argv[1]);
    int *number  =  malloc(sizeof(int) * max);
    int *number1  =  malloc(sizeof(int) * max);
    bzero(number,max);
    bzero(number1,max);
    int i, j;
    clock_t start, finish;
	  double duration;
    srand((unsigned)time(NULL));/*播种子*/
    for(i = 0; i < max; i++)    {
      number[i] = (rand() % 100);/*产生100以内的随机整数*/
      //printf("%d  ",number[i]);
    }
    printf("\n");
    memcpy(number1,number, sizeof(int) * max);
 
	  start = clock();    
    for (i = 1; i < max; i++){
      int e = number[i];
       for (j = i; j > 0 && e < number[j-1];j--){       
          number[j] = number[j-1];          
      }
      number[j] = e;
    }
    // for(i = 0; i < max; i++){

    //     printf("%d " , number[i]);
    // }
   	finish = clock();
    printf("\n");
  	duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("\ninsert sort time = %f CLOCKS_PER_SEC = %d\n",duration, CLOCKS_PER_SEC); 
  	start = clock();
    int min;
    for (i = 0; i < max; i++){
        min = i;
        for (j = i+1; j < max;j++){
          if(number1[min] > number1[j]) {
            min = j;
          }
        }
        swap(&number1[i], &number1[min]);
    }
    finish = clock();
    printf("\n");
  	duration = (double)(finish - start) / CLOCKS_PER_SEC;

    printf("\nselect sort time = %f\n",duration);  
    // for(i = 0; i < max; i++)
    // {
    //    printf(" %d",number1[i]);
    // }
    printf("\n");
    exit(EXIT_SUCCESS);
}