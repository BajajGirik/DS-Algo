#include <stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	int leftOver = n - a - 1;
	printf("%d\n", min(leftOver, b) + 1);

	return 0;
}