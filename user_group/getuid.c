#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>
main()
{
    struct passwd *user;
    printf("getuid = %d geteuid = %d \n", getuid(), geteuid());
    user = getpwnam("root");
    printf("name:%s\n", user->pw_name);
    printf("uid:%d\n", user->pw_uid);
    printf("home:%s\n", user->pw_dir);
    setuid(user->pw_uid);//修改用户的有效ID
 }