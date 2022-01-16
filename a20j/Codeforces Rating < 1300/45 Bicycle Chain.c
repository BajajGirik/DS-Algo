#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);

	int b[m];
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	int maxRatio = 0, noOfIntegers = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (maxRatio < b[j] / a[i] && b[j] % a[i] == 0)
			{
				maxRatio = b[j] / a[i];
				noOfIntegers = 1;
			}

			else if (maxRatio == b[j] / a[i] && b[j] % a[i] == 0)
				noOfIntegers++;

			else if (maxRatio > b[j] / a[i])
				break;
		}
	}

	printf("%d\n", noOfIntegers);
	return 0;
}