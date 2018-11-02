#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
取出 MAX 中最大的TOP个数据
采用最小堆实现
zhaoxianqiang 2018/11/12
*/
#define MAX    10000000
#define TOP    30
typedef struct 
{
	int num;
	int data[TOP+1];
} minHeap;

void swHeap_bubble_up(int a[], int index) {
	int parent_i = index/2 ,i;
	int moving_data =  a[index];
	for (; index > 1 && moving_data < a[parent_i]; index = parent_i, parent_i = index/2)
	 {
	 	a[index] = a[parent_i];
	 }
	 a[index] = moving_data;
}

void swHeap_percolate_down(int a[], int index) {
	int child_i = index*2;
	int moving_data =  a[index];
	if (child_i+1 <= TOP && a[child_i] > a[child_i+1]) {
		child_i++;
	}
	while(moving_data > a[child_i])
	 {
	 	a[index] = a[child_i];
	 	index = child_i;
	 	child_i = index*2;
	 	if (child_i > TOP )
	 		break;
		if (child_i + 1 <= TOP && a[child_i] > a[child_i+1]) {
			child_i++;
		}
		 
 	 }
	 a[index] = moving_data;
}

int add(minHeap *heap, int n) {
	if (heap->num <= TOP) {
		heap->data[heap->num] = n;
		swHeap_bubble_up(heap->data, heap->num);
		heap->num++;
	} else {
		if (heap->data[1] < n) {
			heap->data[1] = n;
			swHeap_percolate_down(heap->data, 1);
		}
	}
}
void print_heap(minHeap *heap){
	if (heap != NULL) {
		int i = 1;
		for (; i < heap->num; i++)
		{
			printf(" heap index: %d  data: %d\n", i, heap->data[i] );
		}
	}
}

int main(int argc, char const *argv[])
{
	minHeap  topheap;
	topheap.num=1;	 
	srand((unsigned)time(NULL));/*播种子*/
	int i;
    for(i = 0; i <= MAX; i++)
    {
        int number = (rand() % MAX);/*产生MAX以内的随机整数*/
        add(&topheap, number);
        //printf("%d ", number[i]);
     }
	print_heap(&topheap);
	return 0;
}