
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
void permutation (int offset)
{
    int i, temp;
    if (offset == N - 1)
    {
        out_print();
        return;
    }
    else
    {
        for ( i = offset; i < N; i++)
        {
            swap(i, offset);
            permutation(offset + 1);
            swap(i, offset);
        }
        
    }
    
}
void swap(int offset, int i)
{
    int temp;
    temp = a[offset];
    a[offset] = a[i];
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

