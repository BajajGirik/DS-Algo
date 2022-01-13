#include <stdio.h>

int minimum(int x, int y)
{
	if (x < y)
		return x;

	return y;
}

int main()
{
	int n;
	scanf("%d", &n);

	int l, r, noOfLOpen = 0, noOfROpen = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &l, &r);
		if (l == 1)
			noOfLOpen++;
		if (r == 1)
			noOfROpen++;
	}

	printf("%d\n", minimum(noOfLOpen, n - noOfLOpen) + minimum(noOfROpen, n - noOfROpen));
	return 0;
}