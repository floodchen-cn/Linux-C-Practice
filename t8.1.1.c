
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  t8.1.1.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月06日
    *Time:16点32分58秒
    *Description:

**********************************************************************************/
#include <stdio.h>

int main()
{
   int a[5] = {1,2,3,4,5};
   int b[5] = {6,7,8,9,10};
   int temp1, temp2;

   for (int i = 0; i < 5; i++)
   {
       temp1 = a[i];
       temp2 = b[i];
       b[i] = temp1;
       a[i] = temp2;
   }
   
   return 0;
}
