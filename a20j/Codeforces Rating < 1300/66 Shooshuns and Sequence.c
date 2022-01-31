#include <stdio.h>
#define ll long long int

int main()
{
	ll n, k;
	scanf("%lld %lld", &n, &k);

	ll a[n];
	for (ll i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	for (ll i = k - 1; i < n - 1; i++)
		if (a[i] != a[i + 1])
		{
			printf("-1\n");
			return 0;
		}

	ll minMoves;
	for (ll i = 0; i < k - 1; i++)
	{
		if (a[i] != a[k - 1])
			minMoves = i + 1;
	}

	printf("%lld\n", minMoves);
	return 0;
}