#include <stdio.h>

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n, minAdd=0;
		int d, i;
		scanf("%lld %d",&n,&d);
		i = 10;
	    long long int original = n;	
		while(n)
		{
			int temp = n%10;
			if(temp == d)
			{
				minAdd = i - original%i;
				if(d == 0)
					minAdd += i/10;	
			}
			i *= 10;
			n /= 10;
		}
		printf("%lld\n",minAdd);
	}
	return 0;
}
