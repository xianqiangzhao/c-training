 //非局部跳转
//执行结果
/*
[root@MiWiFi-R3-srv proc]# ./jmp
setjmp 1
*/
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
		printf("setjmp %d \n", set);
	else 
	 cmd_add();
	exit(0);
}


void
cmd_add(void)
{ 
 	longjmp(jmpbuffer, 1);
 }
