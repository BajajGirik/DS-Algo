#include<stdio.h>
#define ll long long int

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",2*gcd(x,y));
	}
	return 0;
}

