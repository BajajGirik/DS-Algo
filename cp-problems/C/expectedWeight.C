#include<stdio.h>
#define ll long long int
#define MOD 998244353

ll modInverse(ll a)
{
	ll m = MOD;
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        ll q = a / m;
        ll t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll ans;
		ans = ((n%MOD)*((n+1)%MOD)%MOD + MOD )%MOD;
		ans = ((ans * (n+1)%MOD)%MOD + MOD ) %MOD;
		ans = ((ans * modInverse(4))%MOD + MOD)%MOD;
		printf("%lld\n",ans);		
	}
	return 0;
}
