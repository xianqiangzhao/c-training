#include <stdio.h>
#include <string.h>
/*
有效的括号
https://leetcode-cn.com/problems/valid-parentheses/description/
*/
int isValid(char* s) {
    
    char *tmp = strdup(s), *ptr;
    bzero(tmp, strlen(tmp));
    ptr = tmp;
    for (; *s != '\0'; s++) {
        if (*s == '(' ||   *s == '{'  ||  *s == '[' ) {
            *tmp++ = *s;
        } else if (*s == ')' && *(tmp -1) != '(') { 
            return 1;            
        }else if (*s == '}' && *(tmp -1) != '{') { 
            return 1;            
        } else if (*s == ']' && *(tmp -1) != '[') { 
            return 1;        
        } else if (*(tmp -1) == 0){
            return 1;
        } else {
            if (ptr >= tmp )
                return 1;
            else 
                tmp --;
        }
    
    }
    return  (tmp - ptr) == 0?0 :1;
    
}
int main(int argc, char const *argv[])
{
    char *s = "()";
    printf("%d\n", isValid(s) );
    return 0;
}
