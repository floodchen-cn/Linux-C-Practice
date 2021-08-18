
/*********************************************************************************

    *Copyright(C),1996-2021, XiDian University
    *FileName:  t8.5.c
    *Author:  陈锡颖
    *Version:  V1.0
    *Date:2021年08月13日
    *Time:15点51分14秒
    *Description:

**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	char gesture[3][10] = { "剪刀", "石头", "布" };
	int man, computer, result, ret;

	srand(time(NULL));
	while (1) {
		computer = rand() % 3;
	  	printf("\n请输入以下三个数字代表你要出的手势 (0-剪刀 1-石头 2-布):\n");
		ret = scanf("%d", &man);
	  	if (ret != 1 || man < 0 || man > 2) {
			printf("你小子在出什么玩意？ 0, 1 或 2，不玩滚\n");
			continue;
		}
		printf("Your gesture: %s\tComputer's gesture: %s\n", 
			gesture[man], gesture[computer]);

		result = (man - computer + 4) % 3 - 1;
		if (result > 0)
			printf("OK你赢了，有屁用？\n");
		else if (result == 0)
			printf("平局，再来！\n");
		else
			printf("输了!什么辣鸡\n");
	}
	return 0;
}