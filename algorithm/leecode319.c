//https://leetcode.com/problems/bulb-switcher/discuss/77104/Math-solution..
#include <stdio.h>
#include <math.h>
#include <assert.h>

 

 void bulbSwitch(int n) {
 	n = 100;
	int i = sqrt(100);
 //   return i;
}

int digui(n){
	if (n == 0 ) return 1;
	return n * digui(n-1);
}
int main(int argc, char const *argv[])
{
	
	printf("%d\n", digui(5)/digui(5-2) );
	assert(1 ==0);
	return 0;
}