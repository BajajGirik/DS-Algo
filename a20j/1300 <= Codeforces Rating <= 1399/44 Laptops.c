#include <stdio.h>
#include <stdlib.h>
#define ll long long int

struct laptops
{
	ll price, quality;
};

ll cmp(const void *a, const void *b)
{
	return ((struct laptops *)a)->price - ((struct laptops *)b)->price;
}

int main()
{
	ll n;
	scanf("%lld", &n);

	struct laptops a[n];
	for (int i = 0; i < n; ++i)
		scanf("%lld %lld", &a[i].price, &a[i].quality);

	qsort(a, n, sizeof(struct laptops), cmp);

	int lastQuality = -1;
	for (int i = 0; i < n; ++i)
	{
		if (lastQuality > a[i].quality)
		{
			printf("Happy Alex\n");
			return 0;
		}

		lastQuality = a[i].quality;
	}

	printf("Poor Alex\n");
	return 0;
}