 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>

/*
三路快速排序
改进 
1，基准值的选取，随机数选取
2, 和基准值相同的数据不处理

real    0m3.038s
user    0m0.903s
sys     0m0.064s

*/
#define  MAX 100000


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void _quickSort3way(int a[], int left, int right){
   
    if (left >= right) return;
    srand((unsigned)time(NULL));
    int index = rand() %(right - left+1) + left;//基准值
    //printf("pivot= %d  %d \n", index, a[index]);
    int i = left+1,j=right;
    int  lt = left, gt = right + 1; //a[left+1 ... lt-1] < v ; a[lt+1...i-1] = v  a[gt ....r ] >v
    swap(&a[left], &a[index]);
    int pivot = a[left];
    //printf(" pivot = %d\n", pivot);
    while(i < gt) {
        if (a[i]  < pivot) {
            swap(&a[i], &a[lt+1]);
            lt++;
            i++;    
        } else if (a[i]  > pivot) {
            swap(&a[i], &a[gt-1]);
            gt--;
            
        } else {
            i++;
        }
    }
    swap(&a[left], &a[lt]);
 
    _quickSort3way(a, left, lt -1);
    _quickSort3way(a, gt, right);
}

void quickSort(int a[],int left,int right)
{
     
     
    _quickSort3way(a,left,right);
         
}

int main()
{
    int number[MAX] = {0}, i;
    struct timeval  start, end;
    srand((unsigned)time(NULL));/*播种子*/
    for(i = 0; i < MAX; i++)
    {
        number[i] = (rand() % MAX);/*产生MAX以内的随机整数*/
        //printf("%d ", number[i]);
     }
     printf("\n" );
     quickSort(number,0, MAX - 1); 
    // for(i=0; i< MAX; i++)
    // {
    //     printf("%d ", number[i]);
    // }
    return 0;
}