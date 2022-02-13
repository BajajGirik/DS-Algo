#include <stdio.h>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	ll a[n];
	for (ll i = 0; i < n; ++i)
		scanf("%lld", &a[i]);

	ll start = -1, end = -1;
	for (ll i = 0; i < n - 1; ++i)
	{
		if (a[i + 1] < a[i] && start == -1)
			start = i;
		else if (a[i + 1] < a[i] && end != -1)
		{
			printf("no\n");
			return 0;
		}
		else if (a[i + 1] > a[i] && start != -1 && end == -1)
			end = i;
	}

	if (start == -1)
		start = n - 1;
	if (end == -1)
		end = n - 1;

	if ((start - 1 >= 0 && a[end] < a[start - 1]) || (end + 1 <= n - 1 && a[start] > a[end + 1]))
	{
		printf("no\n");
		return 0;
	}

	printf("yes\n");
	printf("%lld %lld\n", start + 1, end + 1);
	return 0;
}