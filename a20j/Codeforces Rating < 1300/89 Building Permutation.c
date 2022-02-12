#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int

ll cmp(const void * a, const void *b)
{
	return *(ll *)a - *(ll *)b;
}

int main() 
{
	ll n;
	scanf("%lld", &n);

	ll a[n], moves = 0;

	for(ll i=0; i<n;++i)
		scanf("%lld", &a[i]);

	qsort(a, n, sizeof(ll), cmp);

	for(ll i=0; i<n; ++i)
		moves += abs(a[i] - i - 1);

	printf("%lld\n", moves);
	return 0;
}
