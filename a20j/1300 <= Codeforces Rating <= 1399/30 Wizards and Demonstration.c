#include <stdio.h>
#include <math.h>
#define ll long long int

int main()
{
	ll n, x, y;
	scanf("%lld %lld %lld", &n, &x, &y);

	double ans = (y * n / 100.0) - x;

	if (ans < 0)
		printf("0\n");
	else
		printf("%lld\n", (ll)ceil(ans));

	return 0;
}
