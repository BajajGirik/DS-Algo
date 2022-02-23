#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int sumOfN = n * (n + 1) / 2;
	m = m % sumOfN;

	for (int i = 1; i <= n; ++i)
	{
		if (i > m)
			break;
		m -= i;
	}

	printf("%d\n", m);
	return 0;
}