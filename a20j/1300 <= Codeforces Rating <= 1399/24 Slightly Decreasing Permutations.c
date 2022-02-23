#include <stdio.h>
#define ll long long int

int main()
{
	ll n, k;
	scanf("%lld %lld", &n, &k);

	for (ll i = n; i > n - k; --i)
		printf("%lld ", i);
	for (ll i = 1; i <= n - k; ++i)
		printf("%lld ", i);

	printf("\n");
	return 0;
}

// 5 2
/*
1 2 3 4 5   ( 5, 0 )
5 4 1 2 3   ( 5, 2 )
5 4 3 1 2   ( 5, 3 )
*/
