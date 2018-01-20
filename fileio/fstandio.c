#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
  	 //int c;
  	 // while ((c = getc(stdin)) != EOF)
 	 // 	if (putc(c, stdout) == EOF)
 	 // 		perror("output error");
 	 
	int size = atoi(argv[1]); 
  	//printf(" buf size is = %d\n",size);
 	char buf[size];
	 while (fgets(buf,size, stdin) != NULL) {
  	 	if (fputs(buf, stdout) == EOF)
 	 		perror("output error");
 	 }  
 	 exit(0);
 	
}
