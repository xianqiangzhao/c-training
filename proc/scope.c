#include <stdio.h>
#include <stdlib.h>

int
f1(int val)
{
	int		num = 0;
	int		*ptr = &num;

	if (val == 0) {
		int		a;

		a = 5;
		ptr = &a;
	}
	return(a + 1);
}

int main(int argc, char const *argv[])
{
	
	int a =0;
	printf("%d" ,f1(a));
	return 0;
}