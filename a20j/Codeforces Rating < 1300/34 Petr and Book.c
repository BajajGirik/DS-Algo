#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int a[7], total = 0;
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &a[i]);
		total += a[i];
	}

	int pagesLeft = n % total;

	if (pagesLeft == 0)
	{
		for (int i = 6; i >= 0; i--)
		{
			if (a[i] != 0)
			{
				printf("%d\n", i + 1);
				return 0;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		pagesLeft -= a[i];
		if (pagesLeft <= 0)
		{
			printf("%d\n", i + 1);
			break;
		}
	}

	return 0;
}