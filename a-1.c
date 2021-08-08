
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  a-1.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月06日
    *Time:16点40分35秒
    *Description:

**********************************************************************************/
#include <stdio.h>

int main()
{
    int a[2] = { 0, 1 };
    int b = -1;
    printf("%d\n",a[-1]);
    
    for (int i = 0 ; i < 2; i++)
    {
        printf("%p\n",&a[i]);
        if (i == 1)   
        {
        printf("%p\n",&i);
        printf("%d\n",a[-1]);
        }
    }
    printf("%p\n",&b);
    return 0;
}
