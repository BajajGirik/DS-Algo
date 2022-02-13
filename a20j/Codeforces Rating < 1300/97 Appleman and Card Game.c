#include <stdio.h>
#include <stdlib.h>
#define ll long long int

ll cmp(const void *a, const void *b)
{
	return *(ll *)b - *(ll *)a;
}

int main()
{
	ll n, k;
	scanf("%lld %lld", &n, &k);

	ll alphabets[26] = {0};
	char s[n + 1];
	scanf("%s", s);

	for (ll i = 0; i < n; ++i)
		++alphabets[(int)(s[i] - 'A')];

	qsort(alphabets, 26, sizeof(ll), cmp);

	ll total = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (k <= alphabets[i])
			break;

		total += alphabets[i] * alphabets[i];
		k -= alphabets[i];
	}

	total += k * k;

	printf("%lld\n", total);
	return 0;
}