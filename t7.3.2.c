
/*********************************************************************************

   *Copyright(C),1996-2021, XiDian University
   *FileName:  t7.3.2.c
   *Author:  陈锡颖
   *Version:  V1.0
   *Date:2021年08月06日
   *Time:10点06分24秒
   *Description:

**********************************************************************************/
#include <stdio.h>

enum coordinate_type {RECTANGULAR  = 1, POLAR};

int main()
{
   int RECTANGULAR;
   printf("%d %d \n",RECTANGULAR, POLAR);
   return 0;
}
//枚举类型的成员名和变量名是处于同一个命名空间，同时在int定义一个变量的时候会将此变量赋0