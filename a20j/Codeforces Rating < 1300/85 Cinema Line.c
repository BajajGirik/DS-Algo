#include<stdio.h>
#include<stdbool.h>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	ll count25 = 0, count50 = 0, count100 = 0;
	bool res = true;
	for(ll i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);

		if(temp == 25)
			++count25;
		else if(temp == 50 && count25 >= 1)
		{	
			--count25;
			++count50;
		}
		else if(temp == 100 && count25 >= 1 && count50 >= 1)
		{
			--count25;
			--count50;
			++count100;
		}
		else if(temp == 100 && count25 >= 3)
		{
			count25 -= 3;
			++count100;
		}
		else
			res = false;
	}

	res ? printf("YES\n") : printf("NO\n");
	return 0;
}
