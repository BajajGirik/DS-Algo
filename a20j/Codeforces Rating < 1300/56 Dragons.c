#include <stdio.h>
#include <stdlib.h>

struct dragons
{
	int strength, bonus;
};

int cmp(const void *a, const void *b)
{
	struct dragons *ptra = (struct dragons *)a;
	struct dragons *ptrb = (struct dragons *)b;

	return (ptra->strength - ptrb->strength);
}

int main()
{
	int s, n;
	scanf("%d %d", &s, &n);

	struct dragons a[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].strength, &a[i].bonus);

	qsort(a, n, sizeof(struct dragons), cmp);

	for (int i = 0; i < n; i++)
	{
		if (a[i].strength >= s)
		{
			printf("NO\n");
			return 0;
		}

		s += a[i].bonus;
	}

	printf("YES\n");
	return 0;
}