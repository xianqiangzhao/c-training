 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>

 #define  MAX 100

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
 int
 main(int argc, char *argv[])
 {

    int number[MAX] = {0};
    int i, j;
    struct timeval  start, end;
    srand((unsigned)time(NULL));/*播种子*/
    for(i = 0; i < MAX; i++)
    {
      number[i] = (rand() % 100);/*产生100以内的随机整数*/
      //printf("%d\n",number[i]);
    }
    printf("\n");
    gettimeofday(&start);
    
    for (i = 1; i < MAX; i++){
      for (j = i; j > 0;j--){
        if(number[j] > number[j-1]) {
          swap(&number[j], &number[j-1]);
        } else {
          break;
        }
      }
    }
    //  for(i = 0; i < MAX; i++)
    // {
    //    printf(" %d",number[i]);
    // }
    printf("\n");
    gettimeofday(&end);
    printf("time = %d  %d\n",end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec); 


    printf("\n");
    gettimeofday(&start);
    for (i = 0; i < MAX; i++){
      for (j = i+1; j < MAX;j++){
        if(number[i] > number[j]) {
          swap(&number[i], &number[j]);
        } 
      }
    }
    for(i = 0; i < MAX; i++)
    {
       printf(" %d",number[i]);
    }
    printf("\n");
    gettimeofday(&end);

    printf("time = %d  %d\n",end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec); 



  
    exit(EXIT_SUCCESS);
 }