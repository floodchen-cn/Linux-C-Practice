
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  leetcode14.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年09月19日
    *Time:14点34分21秒
    *Description:

**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
#define TRUE 1
#define FALSE 0
int array_eaual_test(char*);
char* longestCommonPrefix(char** strs, int strsSize) {
    int width = strsSize / sizeof(strs[0]);
    int lenth = sizeof(strs[0]) / sizeof(strs[0][0]);
    char* common_prefix = (char*)malloc(width * sizeof(char));
    char* result = (char*)malloc(lenth * sizeof(char));
    memset(result, '\0', lenth);
    if (strsSize == 0)
        return result;
    int i = 0, j = 0;
    while (j < lenth && i < width) {
        common_prefix[i] = strs[i][j];
        if (i == width - 1 && array_eaual_test(common_prefix)) {
            result[j] = common_prefix[0];
            i = 0;
            ++j;
        } else
            ++i;
    }
    return result;
}
int array_eaual_test(char* array) {
    int s = strlen(array);
    for (int i = 0; i < s; i++) {
        if (i > 0 && array[i] != array[i - 1])
            return FALSE;
    }
    return TRUE;
}
*/
char* longestCommonPrefix(char** strs, int strSize) {
    char* str = strs[0];  //利用第一个来判断
    int i, j;
    if (strSize == 0)
        return NULL;
    for (i = 1; i < strSize; i++) {
        j = 0;
        while (str[j] && strs[i][j] && str[j] == strs[i][j])
            j++;        //避免数组溢出并判断下一个元素是否相同
        str[j] = '\0';  //字符串结束符只输出前面对应相同的
    }
    return str;
}

int main() {
    char* strs[] = {"pretent", "prevent", "prepos", "predo"};
    char** p_strs;
    p_strs = strs;
    /*
    int width = sizeof(strs) / sizeof(strs[0]);
    int lenth = sizeof(strs[0]) / sizeof(strs[0][0]);
    p_strs = (char**)malloc(sizeof(char*) * sizeof(strs));
    for (int i = 0; i < width; i++) {
        p_strs[i] = (char*)malloc(sizeof(char) * 8);
        for (int j = 0; j < lenth; j++) {
            p_strs[i][j] = strs[i][j];
        }
    }
    */
    char* ans = longestCommonPrefix(p_strs, sizeof(strs));
    printf("%s\n", ans);
    return 0;
}
