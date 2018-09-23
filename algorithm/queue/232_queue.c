#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int *arr;
    int top;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
	MyQueue *queue = malloc(sizeof( MyQueue));
	queue->arr = malloc(sizeof(int ) * maxSize);
	queue->top = 0; 

	return queue;
    
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    int top=obj->top++;
    int i;
    for(i = top - 1; i >= 0; i--) 
      	obj->arr[i+1] = obj->arr[i];
    obj->arr[0]= x;//top

    
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    obj->top--;
    return obj->arr[obj->top];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int top=obj->top;
    return obj->arr[top - 1];
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj) {
        return !obj->top;

}

void myQueueFree(MyQueue* obj) {
    obj->top=0;
    free(obj->arr);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */

int main(int argc, char const *argv[])
{	
	int maxSize = 100;
    MyQueue *obj = myQueueCreate(maxSize);
	myQueuePush(obj, 100);
	myQueuePush(obj, 101);
	

	printf("data = %d\n",myQueuePeek(obj));
	myQueuePop(obj);
	printf("data = %d\n",myQueuePeek(obj));

	 

	//int param_4 = myQueueEmpty(obj);
	myQueueFree(obj);
	return 0;
}