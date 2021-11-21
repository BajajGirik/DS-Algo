#include<stdio.h>
#define ll long long int

int main()
{
	ll t;
	scanf("%lld",&t);

	while(t--)
	{
		ll q, p;
		scanf("%lld %lld",&q,&p);

		double ans = p*q;
		if (q>1000)
			ans *= 0.9;

		printf("%lf\n",ans);
	}
	return 0;
}
