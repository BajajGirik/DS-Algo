#include<stdio.h>
#include<limits.h>
#define ll long long int

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);

		ll smallest = LLONG_MAX;
		for(ll i=0;i<n;i++)
		{
			ll temp;
			scanf("%lld",&temp);
			if (temp < smallest)
				smallest = temp;
		}

		printf("%lld\n", (n-1)*smallest);
	}
	return 0;
}
