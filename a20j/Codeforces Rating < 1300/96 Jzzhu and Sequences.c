#include <stdio.h>
#define ll long long int
#define MOD ((ll)1e9 + 7)

int main()
{
	ll x, y, n;
	scanf("%lld %lld %lld", &x, &y, &n);

	ll res[6] = {(x % MOD + MOD) % MOD, (y % MOD + MOD) % MOD, ((y - x) % MOD + MOD) % MOD, (-x % MOD + MOD) % MOD, (-y % MOD + MOD) % MOD, ((x - y) % MOD + MOD) % MOD};

	printf("%lld\n", res[(n - 1) % 6]);
	return 0;
}