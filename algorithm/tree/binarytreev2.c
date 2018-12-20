#include  <stdio.h>
#include <stdlib.h>

typedef struct _bnode bnode;
struct _bnode
{
    int data;
    bnode *l;
    bnode *r;
};

void create_tree(bnode **b) {
    int i;
    scanf("%d", &i);
    if (i == -1) {
        *b = NULL;
        return ;
    } else {
        *b = (bnode *)malloc(sizeof(bnode));
        (*b)->data = i;
        printf("%s %d\n", "请输入第一个左节点", i );
        create_tree((&(*b)->l));
        printf("%s %d\n", "请输入第一个右节点", i );
        create_tree((&(*b)->r));
    }

}

void print_tree(bnode *b) {
    if (b == NULL) {
        return ;
    }
    printf("%d ", b->data);
    print_tree(b->l);
    print_tree(b->r);

}
bnode * find(bnode *b, int d) {
    if (b == NULL) {
        return NULL;
    }
    if (b->data != d) {
        return find(b->l, d);
        return find(b->r, d);
    }
    return b;

}
int main(int argc, char const *argv[])
{
    bnode *t;
    printf("%s\n", "请输入第一个节点 -1 表示没有子节点" );
    create_tree(&t);
    print_tree(t);
    bnode *f = find(t, 4);
    printf("\nfind %d\n", f->data);
    return 0;
}