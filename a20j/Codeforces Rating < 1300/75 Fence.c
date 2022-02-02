#include <stdio.h>
#define ll long long int

int main()
{
	ll n, k;
	scanf("%lld %lld", &n, &k);

	ll sum = 0, i = 0, a[n];
	for (i = 0; i < k; ++i)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
	}

	ll res = 1;
	ll currSum = sum;
	for (; i < n; ++i)
	{
		scanf("%lld", &a[i]);

		currSum = currSum - a[i - k] + a[i];
		if (currSum < sum)
		{
			sum = currSum;
			res = i - k + 2;
		}
	}

	printf("%lld\n", res);
	return 0;
}

/*
1 2 3 1 2     2 3 1 4 5
sum = 9
curr


*/