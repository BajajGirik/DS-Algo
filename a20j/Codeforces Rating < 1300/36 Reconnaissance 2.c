#include <stdio.h>

int abs(int x)
{
	return x > 0 ? x : -1 * x;
}

int main()
{
	int n;
	scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int reconIndex = 0;
	for (int i = 1; i < n; i++)
	{
		if (abs(a[(reconIndex + 1) % n] - a[reconIndex]) > abs(a[(i + 1) % n] - a[i]))
			reconIndex = i;
	}

	printf("%d %d\n", reconIndex + 1, (reconIndex + 1) % n + 1);
	return 0;
}