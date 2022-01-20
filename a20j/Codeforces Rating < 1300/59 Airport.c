#include <stdio.h>
#include <stdlib.h>
#define ll long long int

ll cmp(const void *a, const void *b)
{
	return (*(ll *)a - *(ll *)b);
}

ll sumOfN(ll n, ll start)
{
	return (n * (n + 1) / 2) - (start * (start + 1) / 2);
}

int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);

	ll a[m];
	for (ll i = 0; i < m; i++)
		scanf("%lld", &a[i]);

	qsort(a, m, sizeof(a[0]), cmp);

	ll min = 0, max = 0, peopleLeft = n;
	for (ll i = 0; i < m; i++)
	{
		if (peopleLeft > a[i])
		{
			min += sumOfN(a[i], 0);
			peopleLeft -= a[i];
		}

		else
		{
			min += sumOfN(a[i], a[i] - peopleLeft);
			break;
		}
	}

	peopleLeft = n;

	for (ll i = m - 1; i >= 1; i--)
	{
		if (a[i] == a[i - 1])
			continue;

		if (peopleLeft > (a[i] - a[i - 1]) * (m - i))
		{
			max += (m - i) * sumOfN(a[i], a[i - 1]);
			peopleLeft -= (a[i] - a[i - 1]) * (m - i);
		}

		else
		{
			ll temp = a[i] - peopleLeft / (m - i);
			max += (m - i) * sumOfN(a[i], temp);
			peopleLeft = peopleLeft % (m - i);
			max += temp * peopleLeft;
			peopleLeft = 0;
			break;
		}
	}

	ll temp = a[0] - peopleLeft / m;
	max += m * sumOfN(a[0], temp);
	peopleLeft = peopleLeft % m;
	max += temp * peopleLeft;

	printf("%lld %lld\n", max, min);
	return 0;
}

// n = 5
// m = 3
// 10 11 12

// i = 1
// max = 12
// peopleLeft = 4