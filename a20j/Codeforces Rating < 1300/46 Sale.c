#include <stdio.h>
#include <stdlib.h>

int cmp(void const *a, void const *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	qsort(a, n, sizeof(a[0]), cmp);

	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i] >= 0)
			break;
		sum += -1 * a[i];
	}

	printf("%d\n", sum);
	return 0;
}