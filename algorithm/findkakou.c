#include <stdio.h>
#include <string.h>

int isValid(char* s) {
    
    char *tmp = strdup(s), *ptr;
    bzero(tmp, strlen(tmp));
    ptr = tmp;
    for (;s != NULL; s++) {
        if (*s == '(' ||   *s == '{'  ||  *s == '[' ) {
            *tmp++ = *s;
        } else if (*s == ')' && ptr[strlen(ptr) -1 ] != '(') { 
            return 1;            
        }else if (*s == '}' && ptr[strlen(ptr) -1 ] != '{') { 
            return 1;            
        } else if (*s == ']' && ptr[strlen(ptr) -1 ] != '[') { 
            return 1;            
        } else if (strlen(ptr) == 0){
            return 1; 
        }
    
    }
    return  0;
    
}
int main(int argc, char const *argv[])
{
    char *s = "{()}";
    printf("%d\n", isValid(s) );
    return 0;
}
