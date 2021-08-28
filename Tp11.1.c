
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  Tp11.1.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月21日
    *Time:15点16分40秒
    *Description:插入排序实现  

**********************************************************************************/
#include <stdio.h>

#define LEN 5//数组长度                      
int a[LEN] = { 10, 5, 2, 4, 7 };
void out_print()//输出数组a
{
    int i = 0;
    for ( i = 0; i < LEN; i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");    
}
void insertion_sort(void)
{                                                                  
	int i, j, key;
	for (j = 1; j < LEN; j++) {//j = x的意思是将第x个元素标记为已排序，该循环要遍历每一个没有排序过的元素
		out_print();
		key = a[j];//提取元素
		i = j - 1;//遍历已排序的元素
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i]; //元素右移，a[i]是等待插入的空位，可理解成右移之后留出的空位
			i--;
		}
		a[i+1] = key;//插入key    
	}
	out_print();                            
}

int main(void)
{
	insertion_sort();
	return 0;
}