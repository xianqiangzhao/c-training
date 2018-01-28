#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char   *argv[])
{
  	char c;
  	int i = 0;
  	
  	while ((c = getc(stdin)) != EOF) {
   		if (c == (*argv[1])) {
  			i++;
  		}

  	}
  	printf("count %s is %d \n", argv[1], i);	 
 	exit(0);
 	
}
