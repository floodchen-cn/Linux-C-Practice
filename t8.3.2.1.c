
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  t8.3.2.1.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月09日
    *Time:07点44分06秒
    *Description:排列组合

**********************************************************************************/
#include <stdio.h>
#define N 3

void permutation(int);
void swap(int, int);
void out_print();
int a[N];
int main()
{
    int i;
    for ( i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    permutation(0);
    return 0;
}        
void permutation (int flag)
{
    int i;
    if (flag == N - 1)//flag等于N-1相当于到了数组的尽头
    {
        out_print();
        return;
    }
    else
    {
        for ( i = flag; i < N; i++)
        {
            swap(i, flag);//交换a[i]以及a[flag]
            permutation(flag + 1);//
            swap(i, flag);
        }
        
    }
    
}
void swap(int flag, int i)
{
    int temp;
    temp = a[flag];
    a[flag] = a[i];
    a[i] = temp;
}
void out_print()
{
    int i;for ( i = 0; i < N; i++)
    {
        printf("  %d", a[i]);
    }
    printf("\n");
}

