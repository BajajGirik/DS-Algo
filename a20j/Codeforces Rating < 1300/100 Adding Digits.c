#include <stdio.h>
#define ll long long int

int main()
{
	ll a, b, n;
	scanf("%lld %lld %lld", &a, &b, &n);

	int firstDigit;
	ll rem = a % b;

	rem = rem * 10;
	if (rem % b == 0)
		firstDigit = 0;
	else if (b - rem % b <= 9)
		firstDigit = b - rem % b;
	else
	{
		printf("-1\n");
		return 0;
	}

	--n;
	printf("%lld%d", a, firstDigit);
	while (n--)
		printf("0");

	printf("\n");
	return 0;
}