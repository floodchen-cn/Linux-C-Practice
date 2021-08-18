
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
	  	printf("\nInput your gesture (0-剪刀 1-石头 2-布):\n");
		ret = scanf("%d", &man);
	  	if (ret != 1 || man < 0 || man > 2) {
			printf("Invalid input! Please input 0, 1 or 2.\n");
			continue;
		}
		printf("Your gesture: %s\tComputer's gesture: %s\n", 
			gesture[man], gesture[computer]);

		result = (man - computer + 4) % 3 - 1;
		if (result > 0)
			printf("赢了!\n");
		else if (result == 0)
			printf("打平!\n");
		else
			printf("输了!\n");
	}
	return 0;
}