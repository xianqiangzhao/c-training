#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>
main()
{
    struct passwd *user;
    user = getpwnam("nobody22");
    printf("name:%s\n", user->pw_name);
    printf("uid:%d\n", user->pw_uid);
    printf("home:%s\n", user->pw_dir);
    setuid(user->pw_uid);
    sleep(10);
}