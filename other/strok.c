#include <string.h>
#include <stdio.h>
main(){
    char s[] = "ab-cd  : ef;gh:i-jkl;mnop;qrs-tu: vwx-y;z";
    char *delim = "-";
    char *p;
    printf("%s \n", strtok(s, delim));
    printf("%s \n", strtok(NULL, delim));
    printf("%s ", strtok(NULL, delim));

}
