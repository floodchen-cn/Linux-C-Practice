
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  LeetCode20.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年09月22日
    *Time:19点27分26秒
    *Description:

**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int push(char* a, int top, char elem) {
    a[++top] = elem;
    return top;
}
int pop(char* a, int top) {
    if (top == -1) {
        printf("空栈");
        return -1;
    }
    printf("弹栈元素：%c\n", a[top]);
    top--;
    return top;
}
char reverse_sign(char c) {
    switch (c) {
        case ')':
            return '(';
            break;
        case ']':
            return '[';
            break;
        case '}':
            return '{';
        default:
            break;
    }
    return 0;
}
int isValid(char s[]) {
    int lenth = strlen(s);
    if (lenth % 2)
        return 0;
    char stack[lenth];
    int top = -1;
    for (int i = 0; i < lenth; i++) {
        top = push(stack, top, s[i]);
        if (reverse_sign(s[i + 1]) == stack[top]) {
            top = pop(stack, top);
            i++;
        }
        if (top > 0 && reverse_sign(stack[top]) == stack[top - 1]) {
            top = pop(stack, top);
            top = pop(stack, top);
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}
int main() {
    char s[] = {"(){}}{"};
    /*
    "()"
 "()[]{}"
 "(]"
 "([)]"
 "{[]}"
 */
    int isClose = isValid(s);
    printf("%d\n", isClose);
    return 0;
}
