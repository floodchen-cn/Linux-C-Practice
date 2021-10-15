
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  test_leetcode14.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年09月20日
    *Time:09点09分07秒
    *Description:使一个指针的指针**p指向二维数组str[][]

**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char strs[3][8] = {"flower", "flow", "flight"};
    char** p_strs;
    int s = sizeof(strs[0]);
    p_strs = (char**)malloc(sizeof(char*) * 3);
    for (int i = 0; i < 3; i++) {
        p_strs[i] = (char*)malloc(sizeof(char) * 8);
        for (int j = 0; j < 8; j++) {
            p_strs[i][j] = strs[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%s\n", p_strs[i]);
    }
    return 0;
}
