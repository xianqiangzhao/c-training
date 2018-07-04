#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
       int val;
      struct ListNode *next;
} vnode;
  
struct ListNode * removeElements(struct ListNode* head, int val) {
    
	  // if (!head) return NULL;
   //      head->next = removeElements(head->next, val);
   //      return head->val == val ? head->next : head;
	/*
	while (head != NULL && head->val == val)
		head = head->next;
	if (head == NULL) return  NULL;

	struct ListNode* prev = head;
	while(prev->next != NULL) {
		if (prev->next->val == val) {
			prev->next = prev->next->next;
		} else {
			prev = prev->next;
		}

	}
    return  head;
    */
      struct  ListNode  *dummyhead = malloc(sizeof(struct  ListNode ));
      dummyhead->next = head;
      struct ListNode* prev = dummyhead;
      while(prev->next != NULL) {
            if (prev->next->val == val) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }

        }
        return  dummyhead->next;
        
}

struct ListNode * createElements( int val) {
	  struct ListNode* node = malloc(sizeof( struct ListNode));
	  node->val = val;
	  node->next = NULL;
	  return node;
   
}


int main(int argc, char const *argv[])
{
	int i;
	struct ListNode * head ,*node ,* tmp;
	head = createElements(1);
	tmp = head;

	node = createElements(2);
	tmp->next = node;
	tmp = node;

	node = createElements(1);
	tmp->next = node;
	tmp = node;

	// node = createElements(4);
	// tmp->next = node;
	// tmp = node;
	 
	printf("%s\n", " init head  ");
	tmp = head;
	while(tmp){
		printf("head.val =  %d\n", tmp->val);
		tmp = tmp->next;
	}
	printf("%s\n", "delete ago");
	head = removeElements(head, 1);
	tmp = head;
	while(tmp){
		printf("head.val =  %d\n", tmp->val);
		tmp = tmp->next;
	}

	return 0;
}