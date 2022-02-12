#include <stdio.h>
#include <stdlib.h>
#define ll long long int

ll cmp(const void *a, const void *b)
{
	return *(ll *)a - *(ll *)b;
}

int main()
{
	ll n;
	scanf("%lld", &n);

	ll a[n], unSortedSumArr[n], sortedSumArr[n];
	ll sum = 0;

	for (ll i = 0; i < n; ++i)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
		unSortedSumArr[i] = sum;
	}

	// for (ll i = 0; i < n; ++i)
	// {
	// 	printf("%lld ", unSortedSumArr[i]);
	// }
	// printf("\n");

	qsort(a, n, sizeof(ll), cmp);
	sum = 0;

	for (ll i = 0; i < n; ++i)
	{
		sum += a[i];
		sortedSumArr[i] = sum;
	}

	ll m;
	scanf("%lld", &m);

	while (m--)
	{
		int type;
		ll l, r;
		scanf("%d %lld %lld", &type, &l, &r);

		if (type == 1 && l - 2 >= 0)
			printf("%lld\n", unSortedSumArr[r - 1] - unSortedSumArr[l - 2]);
		else if (type == 1)
			printf("%lld\n", unSortedSumArr[r - 1]);

		else if (type == 2 && l - 2 >= 0)
			printf("%lld\n", sortedSumArr[r - 1] - sortedSumArr[l - 2]);
		else
			printf("%lld\n", sortedSumArr[r - 1]);
	}

	return 0;
}