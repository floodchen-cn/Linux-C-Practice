
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  t11.4.1.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月27日
    *Time:14点10分48秒
    *Description:

**********************************************************************************/
#include <stdio.h>
#define LEN 8

void out_print(int* a) {
    for (int i = 0; i < LEN; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
void swap(int x, int y, int* a) {
    int temp = 0;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
int partition(int start, int end, int* a) {
    /*
从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
    在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
    使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素;
    return mid;
*/
    int pivot = a[start];
    int i, store_index = start + 1;
    for (i = start + 1; i < LEN; i++) {
        if (a[i] < pivot) {
            swap(i, store_index, a);
            store_index++;
        }
    }
    swap(start, store_index - 1, a);
    return store_index - 1;
}
void quicksort(int start, int end, int* a) {
    int mid;
    if (end > start) {
        mid = partition(start, end, a);
        quicksort(start, mid - 1, a);
        quicksort(mid + 1, end, a);
    }
    out_print(a);
}
int main() {
    int a[LEN] = {8, 7, 6, 5, 4, 3, 2, 1};
    quicksort(0, LEN, a);
    return 0;
}
