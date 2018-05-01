#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
删除链表中的节点
https://leetcode-cn.com/problems/delete-node-in-a-linked-list/description/
*/
typedef struct ListNode{
    int val;
    struct ListNode *next;
} Node;

void deleteNode(struct ListNode* node) {
    node->val=node->next->val;
    node->next=node->next->next;    
}

int main(int argc, char const *argv[])
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->val = 1;
    head->next = NULL;

    Node *new = (Node *)malloc(sizeof(Node));
    new->val = 2;
    new->next = NULL;
    head->next = new;

    Node *loop = head;
    while(loop) {
        printf("%d \n", loop->val);
        loop = loop->next;
    }
  
    return 0;
}
