#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int x[n], y[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);

	int totalSuper = 0;
	for (int i = 0; i < n; i++)
	{
		int left, right, top, bottom;
		left = right = top = bottom = 0;

		for (int j = 0; j < n; j++)
		{
			if (x[j] > x[i] && y[j] == y[i])
				right++;

			else if (x[j] < x[i] && y[j] == y[i])
				left++;

			else if (x[j] == x[i] && y[j] < y[i])
				bottom++;

			else if (x[j] == x[i] && y[j] > y[i])
				top++;

			if (left > 0 && right > 0 && top > 0 && bottom > 0)
			{
				totalSuper++;
				break;
			}
		}
	}

	printf("%d\n", totalSuper);
	return 0;
}