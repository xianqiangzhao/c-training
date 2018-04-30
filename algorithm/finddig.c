#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
两数之和
https://leetcode-cn.com/problems/two-sum/description/

*/
int* twoSum(int* nums, int numsSize, int target) {
    int i,j, *ptr;
    ptr = malloc(sizeof(int) * 2);
    bzero(ptr,sizeof(int) * 2);
    for (i = 0; i < numsSize; ++i)
    {
      for (j = i + 1 ; j < numsSize; ++j)
      {
        if (nums[i] + nums[j] == target) {
            ptr[0] = i;
            ptr[1] = j;            
            return  ptr ; 
        }
      }
    }
    return  NULL;
}

int len(char *s){
    int i = 0;
    while (*s++ != '\0' ) {
        i++;
    }
    return i;

}

int main(int argc, char const *argv[])
{

    char c[6] = "abcef";
    printf("%d\n",len(c) );
    int   s[4] = {2, 7, 11, 15} ,*rs, i, target = 9;
    rs =  twoSum(s , 4, 17);
    printf("target = %d\n", target);
    for (i = 0; rs != NULL && i < 2; i++) {
        printf("rs[%i] %d\n", i, rs[i]);
    }
    free(rs);
    return 0;
}
