#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
double link training
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
	struct node_s *prev;
	struct node_s *next;
   
};
static node head, *last;

node *initList()
{	
	head.next = NULL;
	head.prev = NULL;
	last = &head;	 
}

//add node
int add(node *elem)
{
	if(!elem)
		return NG;
	last->next = elem;
	elem->prev = last;
	elem->next = NULL;
	last = elem;

}
//print link
void printList()
{
	node *p;
	p = &head;
	p = p->next;
    while(p){
    	printf("%d ,",p->data);
    	p = p->next;
    }
    printf("\n");

}

//print link from last start
void printListFromLast()
{
	node *p = last;
    while(p && p != &head) {
    	printf("%d ,",p->data);
    	p = p->prev;
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
			node *d = p->next;
			p->next = d->next;
			if (d != last)
				d->next->prev = p;
			free(d);
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
	for (; i < 10; i++) {
		node *new = zmalloc(sizeof(node));
		new->data = i;
		add(new);
	}
	//print all node
	//printList();
 
 	//find node
	node  *f = findNode(9);
	if (f){
		printf("fined %d\n", f->data);
	} else {
		printf(" not  fined \n");
	}
	
	//delete node
	delNode(0);
	printList();
	printListFromLast();
	return 0;
}