#include <stdio.h>
#define abs(x) ((x > 0) ? (x) : (-1 * x))
#define ll long long int

int main()
{
	ll x, y;
	scanf("%lld %lld", &x, &y);

	ll x1 = abs(x) + abs(y);

	if (x > 0 && y > 0)
		printf("%d %lld %lld %d\n", 0, x1, x1, 0);
	else if (x < 0 && y > 0)
		printf("%lld %d %d %lld\n", -x1, 0, 0, x1);
	else if (x < 0 && y < 0)
		printf("%lld %d %d %lld\n", -x1, 0, 0, -x1);
	else
		printf("%d %lld %lld %d\n", 0, -x1, x1, 0);

	return 0;
}