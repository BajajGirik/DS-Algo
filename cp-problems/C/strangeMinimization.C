#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define ll long long int

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n, i;
		scanf("%lld",&n);
		int flag = 0;	
		for(i=2;i<=sqrt(n);i++)	
		{
			if(n%i == 0)
			{
				flag = 1;
				break;
			}
		}

		ll ans = (n/i)*(i+1);
		if (flag == 0)
			ans = n+1;
		printf("%lld\n",ans);
	}
	return 0;
}
