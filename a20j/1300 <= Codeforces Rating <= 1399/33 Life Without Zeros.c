#include <stdio.h>
#define ll long long int

ll withoutZeros(ll n)
{
	ll noZero = 0;
	ll mul = 1;
	while (n != 0)
	{
		if (n % 10 == 0)
		{
			n = n / 10;
			continue;
		}

		noZero += mul * (n % 10);
		mul *= 10;
		n /= 10;
	}

	return noZero;
}

int main()
{
	ll a, b;
	scanf("%lld\n%lld", &a, &b);

	ll c = a + b;

	ll newA = withoutZeros(a);
	ll newB = withoutZeros(b);
	ll newC = withoutZeros(c);

	if (newA + newB == newC)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}