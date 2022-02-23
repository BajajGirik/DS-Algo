#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long int
#define MAX (ll)1e5 + 2

int main()
{
	char s[MAX];
	scanf("%s", s);

	ll len = strlen(s);
	ll count = 0;
	while (len > 1)
	{
		ll sum = 0;
		for (ll i = 0; i < len; ++i)
			sum += (ll)(s[i] - '0');

		len = sprintf(s, "%lld", sum);
		++count;
	}

	printf("%lld\n", count);
	return 0;
}