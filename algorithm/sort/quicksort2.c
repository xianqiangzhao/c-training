 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>

/*
改进 
1，基准值的选取，随机数选取
2, 左右双路比较。中间是 =pivot的元素，也就是左右平分 = pivot，防止一方偏大。
*/
#define  MAX 3


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right){
   
    srand((unsigned)time(NULL));
    int index = rand() %(right - left+1) + left;//基准值
    //printf("pivot= %d  %d \n", index, a[index]);
    int i = left+1,j=right;//arr[left+1 ... i) <= v ; a(j ....r ] >=v
    swap(&a[left], &a[index]);
    int pivot = a[left];
    printf(" pivot = %d\n", pivot);
    while(1) {
        while (i <= right && a[i] < pivot) i++;
        while (j >= left+1 && a[j] > pivot) j--;
        if (i > j) break;
        swap(&a[i], &a[j]);
        j--;
        i++;
    }
    swap(&a[left], &a[j]);
 
    return j;

}

void quickSort(int a[],int left,int right)
{
    int dp;
    if(left<right)
    {
        dp=partition(a,left,right);
        quickSort(a,left,dp-1);
        quickSort(a,dp+1,right);
    }
}

int main()
{
    int number[MAX] = {0}, i;
    struct timeval  start, end;
    srand((unsigned)time(NULL));/*播种子*/
    for(i = 0; i < MAX; i++)
    {
        number[i] = (rand() % MAX);/*产生MAX以内的随机整数*/
        printf("%d ", number[i]);
     }
     printf("\n" );
     quickSort(number,0, MAX - 1); 
    for(i=0; i< MAX; i++)
    {
        printf("%d ", number[i]);
    }
    return 0;
}