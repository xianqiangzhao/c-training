 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
#define  MAX 100000

void swap(int *data,int pos1,int pos2){
	int tmp=*(data+pos1);
	*(data+pos1)=*(data+pos2);
	*(data+pos2)=tmp;
}

void bubblesort(int *data,int size){
	int i,j;
	for(i=0;i<size-1;i++)
		for(j=0;j<size-1-i;j++)
			if(*(data+j)>*(data+j+1))
				swap(data,j,j+1);
}

void displayoutcome(int *data,int size){
	int i;
	for(i=0;i<size;i++)
		printf("%d ", *(data+i));
	printf("\n");
}

int main(){
	/*
	时间复杂度:O(n^2)
	空间复杂度:O(1)
	思路:对于每个位置，找到最小元素；一次循环后对应位置的数一定是当前最小的。
	*/
	int data[]={60,2,97,78,0,84,68,23,48,22,63,31,43,42,82,9,
		57,21,42,62,83,98,64,72,96,31,76,13,70,49,10,60,72,36,
		26,4,56,54,13,9,98,45,61,90,88,80,30,50,77,83,};
	int size=sizeof(data)/sizeof(int);
	 int number[MAX] = {0}, i;
    struct timeval  start, end;
    srand((unsigned)time(NULL));/*播种子*/
    for(i = 0; i < MAX; i++)
    {
        number[i] = (rand() % MAX);/*产生MAX以内的随机整数*/
       // printf("%d ", number[i]);
     }
     printf("\n" );
	bubblesort(number,MAX);
	//displayoutcome(number,MAX);
	return 0;
}