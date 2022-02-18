#include <stdio.h>
#include <limits.h>
#define ll long long int

int main()
{
	ll n, k, max = LLONG_MIN;
	scanf("%lld %lld", &n, &k);

	for (ll i = 0; i < n; ++i)
	{
		ll f, t, temp;
		scanf("%lld %lld", &f, &t);

		if (t > k)
			temp = f - (t - k);
		else
			temp = f;

		if (temp > max)
			max = temp;
	}

	printf("%lld\n", max);
	return 0;
}