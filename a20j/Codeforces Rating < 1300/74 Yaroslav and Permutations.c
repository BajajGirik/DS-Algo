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
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	qsort(a, n, sizeof(a[0]), cmp);

	int count = 1;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] == a[i - 1])
			++count;
		else
			count = 1;

		if (count > (n + 1) / 2)
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}
