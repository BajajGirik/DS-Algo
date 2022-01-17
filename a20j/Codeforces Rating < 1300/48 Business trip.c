#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)b - *(int *)a);
}

int main()
{
	int k;
	scanf("%d", &k);

	int a[12];
	for (int i = 0; i < 12; i++)
		scanf("%d", &a[i]);

	qsort(a, 12, sizeof(a[0]), cmp);

	int total = 0, i;
	for (i = 0; i < 12; i++)
	{
		if (total >= k || a[i] <= 0)
			break;

		total += a[i];
	}

	if (total >= k)
		printf("%d\n", i);
	else
		printf("-1\n");

	return 0;
}