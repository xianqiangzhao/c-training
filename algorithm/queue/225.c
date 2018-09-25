//用队列实现栈

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {
  STACK_OK,
  STACK_ERR,
};
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
    int num;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *stack = malloc(sizeof(MyStack));
    bzero(stack, sizeof(MyStack));
    stack->maxSize = maxSize;
    stack->front = stack->rear;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->num >= obj->maxSize) {
        obj = realloc(obj, obj->maxSize *2);
        obj->maxSize *= 2;

    }
    QueuePtr node = malloc(sizeof(QNode));
    node->data = x;
    node->next = NULL;
    if (!obj->rear) {
        obj->rear = node;
    }
    else {
       obj->rear->next = node;
    }
    obj->rear = node;
    if (!obj->front) {
     obj->front = obj->rear;
    }
    obj->num++;      
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj->front) {
        QueuePtr node = obj->front;
        obj->front = node->next;
         if (node = obj->rear) {
             obj->rear = obj->front;
        }
        obj->num--;
        return  node->data;
    } else {
        return STACK_ERR;
    }

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->front){        
        return obj->front->data;

    } else{
        return  STACK_ERR;
    }
}

/** Returns whether the stack is empty. */
int myStackEmpty(MyStack* obj) {
    return (obj->front - obj->rear ) ? 1:0;
}

void myStackFree(MyStack* obj) {

    while(obj->front){
    	QueuePtr node  = obj->front;
    	obj->front = node->next;
    	free(node);
    }
    free(obj);
}


void printStack(MyStack *obj){
    QueuePtr tmp = obj->front;
    while(tmp){
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
    printf("stack size = %d num = %d\n", obj->maxSize, obj->num);

}

int main(int argc, char const *argv[])
{
    
    MyStack *stack = myStackCreate(2);
    myStackPush(stack, 100);
    // myStackPush(stack, 200);
    printf("stack is empty = %d\n", myStackEmpty(stack));
    printf("stack top data =  %d\n", myStackTop(stack));
    myStackPop(stack);
    printf("stack is empty = %d\n", myStackEmpty(stack));
    printf("stack top data =  %d\n", myStackTop(stack));
    myStackPush(stack, 100);
    myStackPush(stack, 200);
    myStackPush(stack, 300);
    myStackPush(stack, 400);
    myStackPush(stack, 500);
    printStack(stack);
    myStackPush(stack, 600);
    printStack(stack);

    myStackPop(stack);
    myStackPop(stack);
    myStackPop(stack);
    myStackPop(stack);    
    printStack(stack);

    return 0;
}