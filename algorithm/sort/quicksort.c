 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>

#define  MAX 1000000


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right){
    int l = left;// arr[l...j-1] < v
    int j = l;  //arr[j ... i] >= v
    int i;
    int pivot =  a[l];//基准是最左则第一个元素
    for(i = l+1; i <= right; i++)
    {
        if (a[i] < pivot) {
            swap(&a[i], &a[j+1]);
            j++;
        }
    }
    swap(&a[l], &a[j]);
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
     }
     quickSort(number,0, MAX - 1); 
    for(i=0; i< MAX; i++)
    {
        printf("%d ", number[i]);
    }
    return 0;
}