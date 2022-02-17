#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	if (n <= 10 || n > 21)
		printf("0\n");

	else if (n - 10 == 10)
		printf("15\n");
	else
		printf("4\n");
	return 0;
}