
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  t8.3.1.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月08日
    *Time:16点53分19秒
    *Description:

**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define precompile_lower_bound 0
#define precompile_upper_bound 10
#define Delta (precompile_upper_bound - precompile_lower_bound + 1)
int a[N];
void gen_random(int lower_bound, int upper_bound)
{
    int i;
    srand(time(NULL));
    for (  i = 0; i < N; i++)
    {
        a[i] = lower_bound + rand() %  (upper_bound + 1 - lower_bound);//*决定了生成随机数的范围*
    }
    
}
int main()
{
    int i, j, histogram[Delta] = { 0 };
    gen_random(precompile_lower_bound, precompile_upper_bound);
    for ( i = 0; i < N; i++)
    {
        histogram[a[i]]++;
    }
    for ( i = 0; i < Delta; i++)
    {
        printf("%d\t",i);
    }
    printf("\n");
    for ( j = 0; j < Delta; j++)
    {
        for ( i = 0; i < Delta; i++)
        {
            if (  histogram[i] > 0)
            {
                printf("*\t");
                histogram[i] --;
            }
            else if (histogram[i] <= 0)
            {
                printf("\t");
            }
        }
        i = 0;   
        printf("\n");
    }
    return 0;
} 
