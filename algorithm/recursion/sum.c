#include <stdio.h>
#define MAX 10
int sum(int a[],  int n,int len);
int sum(int a[], int n, int len ) {
	printf("%d, %d \n", n, a[n]);
	if (len == n) 
		return a[n];
	return  sum(a, n + 1, len) + a[n];
}

int main(int argc, char const *argv[])
{
 	int a[MAX] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d\n", sum(a, 0, MAX-1));
	return 0;
}