#include <stdio.h>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	int lastH = -1, lastM = -1;
	ll count = 0, max = 0;

	for (ll i = 0; i < n; ++i)
	{
		int h, m;
		scanf("%d %d", &h, &m);

		if (h == lastH && m == lastM)
			++count;
		else
		{
			count = 1;
			lastH = h;
			lastM = m;
		}

		if (count > max)
			max = count;
	}

	printf("%lld\n", max);
	return 0;
}