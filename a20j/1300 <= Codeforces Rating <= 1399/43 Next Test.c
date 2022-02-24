#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n;
	scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	qsort(a, n, sizeof(int), cmp);

	if (a[0] > 1)
	{
		printf("1\n");
		return 0;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		while (i < n - 1 && a[i] == a[i + 1])
			++i;

		if (i < n - 1 && a[i] + 1 != a[i + 1])
		{
			printf("%d\n", a[i] + 1);
			return 0;
		}
	}

	printf("%d\n", a[n - 1] + 1);
	return 0;
}