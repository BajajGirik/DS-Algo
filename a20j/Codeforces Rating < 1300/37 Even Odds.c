#include <stdio.h>

int main()
{
	long long int n, k;
	scanf("%lld %lld", &n, &k);

	long long int noOfOdd = n / 2 + n % 2;
	int start = 1;

	if (k > noOfOdd)
	{
		k -= noOfOdd;
		start = 2;
	}

	long long int res = start + (k - 1) * 2;
	printf("%lld\n", res);

	return 0;
}