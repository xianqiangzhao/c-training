#include <stdio.h>
#include <pwd.h>
#include <shadow.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	
	struct spwd *pwd;
	if (argc != 2) {
		puts("input username please!");
		exit(1);
	}
	pwd = getspnam(argv[1]);
	if (pwd == NULL ) {
		puts("username is invalid");
		exit(1);
	}
 	printf("%s %s\n", pwd->sp_namp, pwd->sp_pwdp );
	return 0;
	
}