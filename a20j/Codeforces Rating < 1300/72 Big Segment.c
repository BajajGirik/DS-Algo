#include <stdio.h>
#define ll long long int

struct point
{
	ll x, y;
};

int main()
{
	ll n;
	scanf("%lld", &n);

	struct point a[n];
	ll largestYIndex = 0;

	for (ll i = 0; i < n; i++)
	{
		scanf("%lld %lld", &a[i].x, &a[i].y);

		if (a[i].y > a[largestYIndex].y || (a[i].y == a[largestYIndex].y && a[i].x < a[largestYIndex].x))
			largestYIndex = i;
	}

	for (ll i = 0; i < n; i++)
	{
		if (a[i].x < a[largestYIndex].x)
		{
			printf("-1\n");
			return 0;
		}
	}

	printf("%lld\n", largestYIndex + 1);
	return 0;
}