#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
single link training
2018/08/25
*/
#define  OK 0
#define  NG 1
#define  zmalloc  malloc
typedef  struct node_s node;
typedef int data_t;
struct node_s
{
	data_t data;
	struct node_s *next;
   
};
static node head, *last;

node *initList()
{	 
	last = &head;	 
}

//add node
int add(node *elem)
{
	if(!elem)
		return NG;
	last->next = elem;
	elem->next = NULL;
	last = elem;

}
//print link
void printList()
{
	node *p;
	p = &head;
	p = p->next;
    while(p && (p = p->next) != NULL){
    	printf("%d ,",p->data); 
    }
    printf("\n");

}
node *findNode(int find)
{
	node *p;
	p = &head;
	p = p->next;
    while(p && (p = p->next) != NULL){
	    if (p->data == find){
	    	return p;
	    }
    }
    return NULL;
}

//delete node
int delNode(int del)
{
	node *p = &head;	 
	while(p->next){
		if(p->next->data == del){
			free(p->next);
			p->next = p->next->next;
		} else{
			p = p->next;
		}
	}
	return OK;
}


int main(int argc, char const *argv[])
{
	 
	initList();
    int i = 0;
	//add node to link
	for (; i < 100000; i++) {
		node *new = zmalloc(sizeof(node));
		new->data = i;
		add(new);
	}
	//print all node
	//printList();
 
 	//find node
	node  *f = findNode(30);
	if (f){
		printf("fined %d\n", f->data);
	} else {
		printf(" not  fined \n");
	}
	
	//delete node
	delNode(99999);
	printList();
	return 0;
}