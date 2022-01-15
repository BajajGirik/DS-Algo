#include <stdio.h>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		ll temp;
		scanf("%lld", &temp);
		a[temp] = i;
	}

	ll m, v = 0, p = 0;
	scanf("%lld", &m);

	while (m--)
	{
		ll x;
		scanf("%lld", &x);

		v += a[x] + 1;
		p += n - a[x];
	}

	printf("%lld %lld\n", v, p);
	return 0;
}