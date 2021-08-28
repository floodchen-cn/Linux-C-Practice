
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  Tp11.4.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月24日
    *Time:16点22分29秒
    *Description:归并排序的实现

**********************************************************************************/
#include <stdio.h>

#define LEN 9
#define MERGE_TYPE 0
#define SORT_TYPE 1
int a[LEN] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};
void out_print(int start ,int mid ,int end,int print_type)
{
    if (print_type == SORT_TYPE)
    {
        printf("sort\t (%d ~ %d, %d ~ %d)\t\t %d %d %d %d %d %d %d %d %d\n", 
		       start, mid, mid+1, end, 
		       a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
    }
    else if ( print_type == MERGE_TYPE)
    {
        printf("merge\t (%d ~ %d, %d ~ %d) to\t %d %d %d %d %d %d %d %d %d\n", 
		       start, mid, mid+1, end, 
		       a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
    }
    
}
void merge(int start, int mid, int end)
{
	int Lenth_left = mid - start + 1;
	int Lenth_right = end - mid;
	int left[Lenth_left], right[Lenth_right];
	int i, j, k;

	for (i = 0; i < Lenth_left; i++) //将a[start..mid]放进left[] 
		left[i] = a[start+i];
	for (j = 0; j < Lenth_right; j++) //将a[mid+1..end]放进right[]
		right[j] = a[mid+1+j];

	i = j = 0;
	k = start;
	while (i < Lenth_left && j < Lenth_right)//比较left和right的首项
		if (left[i] < right[j])
			a[k++] = left[i++];
		else
			a[k++] = right[j++];

	while (i < Lenth_left) //将left[]剩余的元素放回原来的数组
		a[k++] = left[i++];
	while (j < Lenth_right) //将right[]剩余的元素放回原来的数组
		a[k++] = right[j++];
}

void sort(int start, int end)
{
	int mid;
	if (start < end) {
		mid = (start + end) / 2;

        out_print(start, mid, end, SORT_TYPE);
		sort(start, mid);
		sort(mid+1, end);
		/*递：将数组分组*/
		merge(start, mid, end);
		/*归：合并数组*/
		out_print(start, mid, end, MERGE_TYPE);
	}
}
int main(void)
{
	sort(0, LEN-1);
	return 0;
}