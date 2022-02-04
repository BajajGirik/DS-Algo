#include <stdio.h>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	ll a[n], sum = 0;
	for(ll i=0; i<n-1; ++i)
	{
		ll temp;
		scanf("%lld", &temp);

		sum += temp;
	}

	ll last;
	scanf("%lld", &last);

	last += sum;

	if(last % n == 0)
		printf("%lld\n", n);
	else
		printf("%lld\n", n-1);

	return 0;
}
