 #include <setjmp.h>
 #include <stdio.h>
 #include <stdlib.h>

 
 
jmp_buf	jmpbuffer;
void cmd_add(void);
int
main(void)
{
 	int  set;
	if ((set =  setjmp(jmpbuffer)) != 0)
		printf("error %d", set);

	 cmd_add();

	exit(0);
}

 

void
cmd_add(void)
{
 
 	longjmp(jmpbuffer, 1);
	/* rest of processing for this command */
}
