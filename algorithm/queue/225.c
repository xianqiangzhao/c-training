//用队列实现栈

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int QElemType;
typedef struct QNode
{
    QElemType   data;   	/*数据域*/
    struct QNode   *next;   /*指针域*/
 }QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
    int maxSize;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->maxSize = maxSize;
    stack->front = stack->rear;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
        QueuePtr *node = malloc(sizeof(QNode));
        node->data = x;
        node->next = null;
        obj->rear->next = node;
		obj->rear = node;

}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
     QueuePtr *node = obj->front->next;
     obj->front->next = node->next;
     if (node == obj->rear)
     	obj->front = obj->rear;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return  obj->front->next->data;
}

/** Returns whether the stack is empty. */
int myStackEmpty(MyStack* obj) {
    retrun (obj->front == obj->next) ? 1:0;
}

void myStackFree(MyStack* obj) {
    where(obj->front->next) {
    	QueuePtr *node  = obj->front->next;
    	obj->front->next = node->next;
    	free(node);
    }
    free(obj);
}