#include<stdio.h>
#define ll long long int
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y

int main() 
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		
		ll arr[n];
		for(ll i=0;i<n;i++)
			scanf("%lld",&arr[i]);

		ll smallest = min(arr[0],arr[1]);
		ll sec_smallest = max(arr[0],arr[1]);
		ll temp;
		for(ll i=2;i<n;i++)
		{
			if(arr[i] < smallest) 
			{
				temp = smallest;
				smallest = arr[i];
				sec_smallest = temp;
			}
			else if(arr[i] < sec_smallest)
				sec_smallest = arr[i];
		}

		printf("%lld\n",smallest + sec_smallest);
	}

	return 0;
}
