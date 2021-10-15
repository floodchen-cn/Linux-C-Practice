
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  LeetCode88.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年10月01日
    *Time:08点01分27秒
    *Description:

**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* p_num1 = nums1;
    int* p_num2 = nums2;
    int tmp[nums1Size];
    int i = 0;
    while (p_num1 - nums1 < m || p_num2 - nums2 < n) {
        if (p_num1 - nums1 == m) {
            tmp[i] = *p_num2;
            p_num2++;
        } else if (p_num2 - nums2 == n) {
            tmp[i] = *p_num1;
            p_num1++;
        } else if (*p_num1 < *p_num2) {
            tmp[i] = *p_num1;
            p_num1++;
        } else {
            tmp[i] = *p_num2;
            p_num2++;
        }
        i++;
    }
    for (i = 0; i < nums1Size; i++) {
        nums1[i] = tmp[i];
    }
}

int main() {
    int m = 1;
    int n = 0;
    int nums1[1] = {1};
    int nums2[0] = {};
    for (int i = 0; i < m + n; i++) {
        printf("%d", nums1[i]);
    }
    merge(nums1, 1, m, nums2, 0, n);
    printf("\n");
    for (int i = 0; i < m + n; i++) {
        printf("%d", nums1[i]);
    }
    printf("\n");
    /*,,
    [1,2,3,0,0,0]
    3
    [2,5,6]
    3
    [1]
    1
    []
    0
    [0]
    0
    [1]
    1
    */
    return 0;
}
