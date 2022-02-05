#include <stdio.h>
#include <cmath>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	ll count = 0;

	for (ll a = 1; a < n; ++a)
		for (ll b = a; b <= n; ++b)
		{
			ll c = a * a + b * b;
			if (c > n * n)
				break;
			ll root = sqrt(c);
			if (c == root * root)
				++count;
		}

	printf("%lld\n", count);
	return 0;
}
