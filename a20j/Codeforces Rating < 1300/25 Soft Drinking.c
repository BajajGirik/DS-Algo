#include <stdio.h>

int minimum(int a, int b, int c)
{
	a = a < b ? a : b;
	return a < c ? a : c;
}

int main()
{
	int n, k, l, c, d, p, nl, np;
	scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);

	printf("%d\n", minimum((k * l) / (nl * n), c * d / n, p / (np * n)));
	return 0;
}