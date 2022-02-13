#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);

	int a[n * m];
	for (int i = 0; i < n * m; ++i)
		scanf("%d", &a[i]);

	int rem = a[0] % d;
	for (int i = 1; i < n * m; ++i)
		if (a[i] % d != rem)
		{
			printf("-1\n");
			return 0;
		}

	qsort(a, n * m, sizeof(int), cmp);

	int target = a[n * m / 2], moves = 0;
	for (int i = 0; i < n * m; ++i)
		moves += abs((a[i] - target)) / d;

	printf("%d\n", moves);
	return 0;
}