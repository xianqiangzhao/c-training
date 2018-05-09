#include <stdio.h>
#define paster( n ) printf( "token " #n" = %d\n ", token##n )
int main()
{
int token9=10;
paster(9);
return 0;
}
