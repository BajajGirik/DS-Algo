#include <stdio.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int a[n];
	for (int i = 0; i < n - 1; ++i)
	{
		if (k > 0)
		{
			a[i] = 1;
			--k;
		}
		else
			a[i] = 0;
	}
	a[n - 1] = k;

	for (int i = 0; i < n; i++)
	{
		int j = i;
		do
		{
			printf("%d ", a[j]);
			j = (j + 1) % n;
		} while (j != i);

		printf("\n");
	}
	return 0;
}