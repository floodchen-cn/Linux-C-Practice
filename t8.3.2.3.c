
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  t8.3.2.3.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月09日
    *Time:17点39分17秒
    *Description:

**********************************************************************************/
#include <stdio.h>
#define N 3
#define M 2
void combination(int, int);
void out_print();
int a[N];
int b[M];
int main()
{
    int i;
    for ( i = 0; i < N; i++)
    {
        a[i] = i + 1;
    } 
    combination(M, N);
    return 0;
}        
void out_print()
{
    int i;for ( i = 0; i < M; i++)
    {
        printf("  %d", b[i]);
    }
    printf("\n");
}
void combination(int m, int n)
{
    int i;
    if (m == 0)
    {
        out_print();
        return;
    }
    else
    {
        for ( i = n - 1; i >= 0; i--)
        {
            b[m - 1] = a[i];
            combination(m - 1 ,i);//相当于m--,i--直到
        }
    }
}
