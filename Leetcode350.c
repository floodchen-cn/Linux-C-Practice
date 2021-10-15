
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  Leetcode350.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年10月02日
    *Time:15点59分10秒
    *Description:

**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int x, int y, int* array) {
    int temp = 0;
    temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}
int partition(int start, int end, int* array, int len) {
    int pivot = array[start];
    int i, store_index = start + 1;
    for (i = start + 1; i < len; i++) {
        if (array[i] < pivot) {
            swap(i, store_index, array);
            store_index++;
        }
    }
    swap(start, store_index - 1, array);
    return store_index - 1;
}
void quicksort(int start, int end, int* array, int len) {
    int mid;
    if (end > start) {
        mid = partition(start, end, array, len);
        quicksort(start, mid - 1, array, len);
        quicksort(mid + 1, end, array, len);
    }
}
int* intersect(int* nums1,
               int nums1Size,
               int* nums2,
               int nums2Size,
               int* returnSize) {
    quicksort(0, nums1Size, nums1, nums1Size);
    quicksort(0, nums2Size, nums2, nums2Size);
    int min_size = nums1Size > nums2Size ? nums2Size : nums1Size;
    int* result = (int*)malloc(sizeof(int) * min_size);
    int* p1 = nums1;
    int* p2 = nums2;
    *returnSize = 0;
    while (p1 - nums1 < nums1Size && p2 - nums2 < nums2Size) {
        if (*p1 < *p2) {
            p1++;
        } else if (*p2 < *p1) {
            p2++;
        } else {
            result[(*returnSize)++] = *p1;
            result++;
            p1++;
            p2++;
        }
    }
    return result;
}
int main() {
    int a[4] = {1, 2, 2, 1};
    int b[2] = {2, 2};
    int* result = intersect(a, 4, b, 2, 0);
    for (int i = 0; i < 2; i++) {
        printf("%d", *result);
        result++;
    }

    return 0;
}
