#include <stdio.h>
#include <limits.h>

int maxi(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, a, b, c;
	scanf("%d %d %d %d", &n, &a, &b, &c);

	int max = INT_MIN;
	for(int i = 0; i <= n/a; ++i)
		for(int j = 0; j <= n/b; ++j)
		{
			if((n - a*i - b*j) >= 0 && (n - a*i - b*j)%c == 0)
				max = maxi(i+ j+ (n - a*i - b*j)/c, max);
		}

	printf("%d\n", max);
	return 0;
}
