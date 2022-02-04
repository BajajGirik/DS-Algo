#include <stdio.h>
#define ll long long int

int main()
{
	ll y, k, n;
	scanf("%lld %lld %lld", &y, &k, &n);

	if(y >= n ||  k*((y/k)+1) > n)
	{
		printf("-1\n");
		return 0;
	}

	ll x;
	x = k * ((y/k) + 1) - y;

	for(; x+y <= n; x+=k)
		printf("%lld ", x);

	printf("\n");
	return 0;
}
