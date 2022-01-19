#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int a[m];
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);

	qsort(a, m, sizeof(a[0]), cmp);

	int min = a[n - 1] - a[0];

	for (int i = n; i < m; i++)
	{
		if (min > a[i] - a[i - n + 1])
			min = a[i] - a[i - n + 1];
	}

	printf("%d\n", min);
	return 0;
}