#include <stdio.h>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	for (ll i = 0; i < n; i++)
	{
		printf("%lld ", n + i);
	}

	printf("\n");
	return 0;
}