#include <stdio.h>

int main()
{
	long long int n, m, prev = 1, time = 0;
	scanf("%lld %lld", &n, &m);

	for (long long int i = 0; i < m; i++)
	{
		long long int temp;
		scanf("%lld", &temp);

		time += ((temp - prev) + n) % n;
		prev = temp;
	}

	printf("%lld\n", time);
	return 0;
}