#include<stdio.h>
#include<limits.h>
#define ll long long int

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll a[n];

		for(int i=0; i<n; i++)
			scanf("%lld",&a[i]);

		ll minimum = a[0] , maximum = a[0], second_maximum = LONG_MIN;
		for(int i=1; i<n; i++)
		{
			if(minimum > a[i])
				minimum = a[i];

			if(maximum <= a[i])
			{
				second_maximum = maximum;
				maximum = a[i];
			}

			else if(second_maximum < a[i])
				second_maximum = a[i];
		}

		printf("%lld\n", (maximum-minimum) * second_maximum);
	}
	return 0;
}
