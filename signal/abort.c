#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void sig_abort(int sig ) {

	sleep(3);
	puts("get sig abort");
	exit(1);
}

int main(int argc, char const *argv[])
{
	signal(SIGABRT, sig_abort);
	abort();
	puts("quit");
	return 0;
}