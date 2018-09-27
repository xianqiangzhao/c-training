#include <stdio.h>
#define N 7 // 最小堆得元素个数

int minHeap[N]; // 存放最小堆的数组
int index1 = 0; // 最小堆数组索引

void add(int d) // 向最小堆内添加数据
{
    if(index1 >= N)
    {
        printf("Out of range!\n");
        return;
    }
    int t = index1; // t指向存放位置
    int pt = (t - 1) / 2; // 父节点
    while(t > 0) // t指向0位置时结束循环
    {
        if(minHeap[pt] > d) // 当父节点数据比插入数据大时，将父节点数据下移
        {
            minHeap[t] = minHeap[pt];
            t = pt;
            pt = (t - 1) / 2;
        }
        else // 找到合适位置
            break;
    }
    minHeap[t] = d; // 最后存放数据位置
    index1++;
}
int main()
{
    int t[N] = {100, 1, 7, 3, 17, 19, 36};
    int i;
    for(i=0; i<N; i++)
    {
        add(t[i]);
    }

    for(i=0; i<N; i++) // 输出测试
    {
        printf("%d ", minHeap[i]);
    }
    printf("\n");
    return 0;
}