
#ifndef SYMBOL
#define SYMBOL
#include <stdio.h>
#include <string.h>

struct mem
{
	int size;
	void *data;
} poolempty;

static  int  si = 110;
static entostart(char * string){
	char tmp;
	int maxlen = strlen(string), mid = (int ) (maxlen/2), start = 0;
 	while(maxlen > mid){
		tmp = string[maxlen-1];
		string[maxlen-1] = string[start];
		string[start] = tmp;
		maxlen--;
		start++;
	}

}
#endif