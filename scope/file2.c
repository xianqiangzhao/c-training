#include "file.h"

extern  struct mem  pool; //belong of file.h
extern  int size; //belong of file.h
extern  printsize(); //belong of file.c

int a = 100;
int main(int argc, char const *argv[])
{
	int b;
	printf("poolempty.size = %d\n", poolempty.size );
	printf("pool.size = %d\n", pool.size );
	size = 20;
	printf("%d\n", size );
	printsize();
	si = 200;
	printf("static si = %d\n", si );
	printf("a = %d\n", a );
	printf("b = %d\n", ++b);

    if (b ==1) {
    	int c =23;

    }
    //printf("c = %d\n", c ); error  ‘c’ undeclared 


     enum liquid {OUCE =1,CUP =8, PINT = 16, QUART = 32};
     enum liquid jar;
     jar = PINT;
     printf("enum jar = %d\n", jar);
	 jar+= PINT;
     printf("enum jar = %d\n", jar);
     printf("enum CUP = %d\n", CUP);

     //const
     const int limit = 10;
     const int * limitp = &limit;
     //*limitp =  1;
     printf("limit = %d\n", limit);
	 printf("limitp = %d\n", *limitp);

     //string reversal
     char buf[] = {"ab"}; 
     char *conp = "zxqef";
     //*conp = 'd'; Segmentation fault.
     char *p = buf;
     entostart(p);
     printf("entostart = %s\n", p);
	return 0;
}