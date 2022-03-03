#include <stdio.h>
#include <math.h>
#define ll long long int
#define MAX (ll)1e5

ll lucky_numbers[MAX];
ll ind = 2;

ll countLuckyNumbers()
{
	ll count = 2;
	ll last_count = 2;
	ll digits = 1;

	while (digits < 9)
	{
		count += last_count * 2;
		last_count *= 2;
		++digits;
	}

	return count;
}

void getLuckyNumbers(ll digits)
{
	ll last_count = 2;
	ll currDigits = 1;

	lucky_numbers[0] = 4;
	lucky_numbers[1] = 7;

	while (currDigits <= digits)
	{
		ll mul = pow(10, currDigits);
		ll temp_index = ind;
		for (int i = 0; i < 2; ++i)
		{
			ll temp = lucky_numbers[i] * mul;
			for (ll j = 1; j <= last_count; ++j)
				lucky_numbers[ind++] = temp + lucky_numbers[temp_index - last_count + j - 1];
		}

		last_count *= 2;
		++currDigits;
	}
}

void printLuckyNumbers()
{
	for (ll i = 0; i < ind; ++i)
		printf("%lld\n", lucky_numbers[i]);
}

int main()
{
	ll l, r;
	scanf("%lld %lld", &l, &r);

	

	getLuckyNumbers();
	printLuckyNumbers();
	return 0;
}

/*

last_count = 2
digits = 1
ind  = 2
lucky_numbers = [ 4, 7  I]

mul = 10
temp = 40
*/