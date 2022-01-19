#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= 2 * i - 1; j++)
			printf(" ");

		for (int j = 0; j < n - i + 1; j++)
			printf(" %d", j);

		for (int j = n - i - 1; j >= 0; j--)
			printf(" %d", j);

		printf("\n");
	}

	for (int j = 0; j < n + 1; j++)
		printf("%d ", j);

	for (int j = n - 1; j >= 1; j--)
		printf("%d ", j);

	printf("0\n");

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2 * i - 1; j++)
			printf(" ");

		for (int j = 0; j < n - i + 1; j++)
			printf(" %d", j);

		for (int j = n - i - 1; j >= 0; j--)
			printf(" %d", j);

		printf("\n");
	}

	return 0;
}