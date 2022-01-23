#include <stdio.h>
#include <limits.h>
#define ll long long int

int main()
{
	ll n;
	scanf("%lld", &n);

	ll min, max, temp, noOfMax, noOfMin;
	min = LLONG_MAX;
	max = LLONG_MIN;
	noOfMax = noOfMin = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &temp);
		if (max < temp)
		{
			max = temp;
			noOfMax = 1;
		}
		else if (temp == max)
			noOfMax++;

		if (min > temp)
		{
			min = temp;
			noOfMin = 1;
		}
		else if (min == temp)
			noOfMin++;
	}

	if (min == max)
	{
		min = max;
		noOfMax = 1;
		noOfMin = n * (n - 1) / 2;
	}
	printf("%lld %lld\n", max - min, noOfMax * noOfMin);
	return 0;
}