#include <stdio.h>

int main()
{
	int n, m, total = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i * i <= n; i++)
		for (int j = 0; j * j <= m; j++)
		{
			if (i * i + j > n && i + j * j > m)
				break;

			if (i * i + j == n && i + j * j == m)
				total++;
		}

	printf("%d\n", total);
	return 0;
}