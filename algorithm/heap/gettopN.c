#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
取出 MAX 中最大/最小的TOP个数据
采用最小堆/最大堆实现
zhaoxianqiang 2018/11/12
*/
#define MAX    10000000
#define TOP    10
#define MIN_HEAP  // 定义了该宏是最小堆，否则是最大堆

typedef struct
{	int type;
	int num;
	int data[TOP+1];
} minHeap;

int compare(int a, int b) {
	#ifdef MIN_HEAP
		return a > b;
	#else 
		return a < b;
	#endif
}

int get_max_child(int a[], int index) {
	int child_i = index*2;
 	if (child_i > TOP )
 		return 0;
	if (child_i + 1 <= TOP && compare(a[child_i],a[child_i+1])) {
		child_i++;
	}
	return child_i;

}
void swHeap_bubble_up(int a[], int index) {
	int parent_i = index/2 ,i;
	int moving_data =  a[index];
	for (; index > 1 && compare(a[parent_i], moving_data); index = parent_i, parent_i = index/2)
	 {
	 	a[index] = a[parent_i];
	 }
	 a[index] = moving_data;
}

void swHeap_percolate_down(int a[], int index) {
 	int moving_data =  a[index];
	int child_i;
	while((child_i = get_max_child(a, index)) &&
		 compare(moving_data, a[child_i]))
	 {
	 	a[index] = a[child_i];
	 	index = child_i;		 
 	 }
	 a[index] = moving_data;
}

int add(minHeap *heap, int n) {
	if (heap->num <= TOP) {
		heap->data[heap->num] = n;
		swHeap_bubble_up(heap->data, heap->num);
		heap->num++;
	} else {
		if (compare(n, heap->data[1])) {
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
	//srand((unsigned)time(NULL));/*播种子*/
	int i;
    for(i = 0; i <= MAX; i++)
    {
        //int number = (rand() % MAX);/*产生MAX以内的随机整数*/
        add(&topheap, i);
     }
	print_heap(&topheap);
	return 0;
}