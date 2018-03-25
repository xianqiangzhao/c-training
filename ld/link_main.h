
#ifndef  LINK_H
#define  LINK_H

int  sum(int y);
int base;
typedef struct
{
	char *name;
	int i;
	int (*sum)(int x);
} name_struct;

#endif