#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[n][n];

	int j = n * n;
	for (int i = 0; i + 1 <= j; ++i)
	{
		a[i % n][i / n] = i + 1;
		a[i % n][n - 1 - i / n] = j;
		j--;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%d ", a[i][j]);

		printf("\n");
	}
	return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 1 8 09 16
// 2 7 10 15
// 3 6 11 14
// 4 5 12 13