#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  NUM 10

typedef int elemtype;
typedef struct link_node_s link_node_t;

struct  link_node_s
{
	elemtype data;
	link_node_t *next;
	link_node_t *current;
	link_node_t *(*init)(int i);
	link_node_t *(*add)(link_node_t node);
	link_node_t *(*del)(link_node_t node);
	int max;
	int size;

};

 
//init  link
link_node_t *link_init(int i) {
	link_node_t *head = malloc(sizeof(link_node_t) * i);
	head->next = NULL;
	head->max = i;
	head->size = 0;
	return head;
}

link_node_t *pop(link_node_t link, link_node_t node) {
	if (node == NULl || link == NULL ) {
		return NULL;
	}
	if (link->size >= link->max) {
		link = realloc(link, link->max * 2 * sizeof(link_node_t));
		if (link == NULL)
			return NULL;
	}
	node->next = link;
	link->size++;
	return head;
}

link_node_t *push(link_node_t link, link_node_t node) {

 	head->next = NULL;
	head->size = i;
	return head;
}

link_node_t *malloc(link_node_t link) {
	if (link == NULL ) {
		return NULL;
	}
	if (link->size >= link->max) {
		link = realloc(link, link->max * 2 * sizeof(link_node_t));
		if (link == NULL)
			return NULL;
	}
	link_node_t *new = link + size + 1;
	link->size++;
	return new;

}
link_node_t head = {0, NULL, link_init, add,  del ,0 , 0};

int main(int argc, char const *argv[])
{
 	//init stack
	link_node_t *link =  head.init(NUM);



	/* code */
	return 0;
}