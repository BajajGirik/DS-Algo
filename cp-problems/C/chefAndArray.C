#include <stdio.h>
#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b

void calcNext(long long int *x, long long int *y, long long int N)
{
	*x = (*x + 7) % (N - 1);
	*y = (*y + 11) % N;
}

int main()
{
	long long int n;
	scanf("%lld", &n);

	long long int a[n];
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	long long int m, x1, y1;
	scanf("%lld %lld %lld", &m, &x1, &y1);

	long long int sum = 0;
	while (m--)
	{
		int x2, y2;
		x2 = min(x1, y1);
		y2 = max(x1, y1);

		long long int maximum = a[x2];
		for (int i = x2 + 1; i <= y2; i++)
		{
			if (a[i] > maximum)
			{
				maximum = a[i];
			}
		}

		sum += maximum;
		calcNext(&x1, &y1, n);
	}
	printf("%lld\n", sum);

	return 0;
}
