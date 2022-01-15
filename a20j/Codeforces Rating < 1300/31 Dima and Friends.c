#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int x, sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		sum += x;
	}

	int res = 0;
	for (int i = 0; i < 5; i++)
	{
		sum % (n + 1) != 0 && res++;
		sum++;
	}

	printf("%d\n", res);
	return 0;
}