
/*
作者：Yihulee
链接：https://www.jianshu.com/p/da1d69f0a6ad
來源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <stdio.h>

int main() {
    int num = 0;

    /*
     * n++;
     * __sync_fetch_and_add(10, 3) = 10
     * num = 13
     */
    num = 10;
    printf("__sync_fetch_and_add(%d, %d) = %d\n", 10, 3, __sync_fetch_and_add(&num, 3));
    printf("num = %d\n", num);

    /*
     * ++n;
     * __sync_and_add_and_fetch(10, 3) = 13
     * num = 13
     */
    num = 10;
    printf("__sync_and_add_and_fetch(%d, %d) = %d\n", 10, 3, __sync_add_and_fetch(&num, 3));
    printf("num = %d\n", num);

    /*
     * CAS, match
     * __sync_val_compare_and_swap(10, 10, 2) = 10
     * num = 2
     */
    num = 10;
    printf("__sync_val_compare_and_swap(%d, %d, %d) = %d\n", 10, 10, 2, __sync_val_compare_and_swap(&num, 10, 2));
    printf("num = %d\n", num);

    /*
     * CAS, not match
     * __sync_val_compare_and_swap(10, 3, 5) = 10
     * num = 10
     */
    num = 10;
    printf("__sync_val_compare_and_swap(%d, %d, %d) = %d\n", 10, 3, 5, __sync_val_compare_and_swap(&num, 1, 2));
    printf("num = %d\n", num);

    return 0;
}

