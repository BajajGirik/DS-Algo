#include <stdio.h>
#include <unordered_set>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	ll MAX = (ll)1e6 + 5, i, j;
	std::unordered_set<ll> tprimes;

	tprimes.insert(4);
	for (i = 3; i <= MAX; i += 2)
	{
		if (tprimes.find(i) != tprimes.end())
			continue;

		bool flag = true;
		for (j = 3; j * j <= i; j += 2)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}

		if (flag)
			tprimes.insert(i * i);
	}

	/////////////////
	// for (auto x : tprimes)
	// {
	// 	printf("%lld\n", x);
	// }
	/////////////////

	while (n--)
	{
		ll x;
		scanf("%lld", &x);

		if (tprimes.find(x) != tprimes.end())
			printf("YES\n");
		else
			printf("NO\n");
	}
}