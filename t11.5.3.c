
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  t11.5.3.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月29日
    *Time:16点40分21秒
    *Description:实现k-th Order Statistic(即在一组随机排列的数中找出第k小的)

**********************************************************************************/
#include <stdio.h>
#define LEN 9
int a[LEN] = {8,7,6,5,4,3,2,1,0};
void out_print()
{
    for (int i = 0; i < LEN; i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");
}
void swap(int x, int y)
{
    int temp = 0;
    if (x >= 0 && x < LEN && y >= 0 && y <= LEN)
    {
        temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
    return;
}
int partition_mine(int start, int end)
{
	/*
    从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
	在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
	使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素;
	return mid;
    */
    int pivot = a[start];
    int i,store_index= start + 1;

    for (i = start + 1; i < LEN; i++)
    {
        if (a[i] < pivot)
        {
            swap(i, store_index);
            store_index++;
        }
    }
    swap(start, store_index - 1);
    return store_index - 1 ; 
}
int partition(int start, int end)
{
    int pivotkey = a[start];
 
    while (start < end)
    {
        while (start < end && a[end] >= pivotkey)
            end--;
            a[start] = a[end];
            while (start < end && a[start] <= pivotkey)
            start++;
            a[end] = a[start];
    }
    a[start] = pivotkey;
 
    return start;
}
void order_statistic(int start, int end, int k )
{
    int i,mid;

    mid = partition_mine(start, end);
    i = mid - start + 1 ;
    if (k < i)
        order_statistic(start, mid - 1, k);
    else if (k > i)
        order_statistic(mid + 1, end, k - i);
    else if (k == i)
        printf("此数为%d\n",a[mid]);
    return;
}
int main()
{
    out_print();
    order_statistic(0, LEN - 1, 1);
    out_print();
    return 0;
}
