#include <stdio.h>

int is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			 i = n + 1;		
	if (i == n)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i;
	printf("Prime numbers from 1 to 100 :\n");
	for (i = 1; i <= 100; i++) {
		if (is_prime(i))
			printf(" %d ", i);
	}
	printf("\nend\n");
	return 0;
}
