#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int a[n];
	int maxIndex = 0, minIndex = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);

		if (a[minIndex] >= a[i])
			minIndex = i;

		if (a[maxIndex] < a[i])
			maxIndex = i;
	}

	int result = maxIndex + (n - 1 - minIndex);

	if (maxIndex > minIndex)
		result--;

	printf("%d\n", result);
	return 0;
}