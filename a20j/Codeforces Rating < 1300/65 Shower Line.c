#include <stdio.h>
#define ll long long int

int main()
{
	ll a[5][5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%lld", &a[i][j]);

	ll maxSum = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (j == i)
				continue;
			for (int k = 0; k < 5; k++)
			{
				if (k == i || k == j)
					continue;
				for (int x = 0; x < 5; x++)
				{
					if (x == i || x == j || x == k)
						continue;
					for (int y = 0; y < 5; y++)
					{
						if (y == i || y == j || y == k || y == x)
							continue;

						ll currentSum = (a[i][j] + a[j][i]) + (a[j][k] + a[k][j]) + 2 * (a[k][x] + a[x][k]) + 2 * (a[x][y] + a[y][x]);
						if (currentSum > maxSum)
							maxSum = currentSum;
					}
				}
			}
		}
	printf("%lld\n", maxSum);
	return 0;
}