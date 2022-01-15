#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	long long int result = sqrt((a * b) / c) + sqrt((b * c) / a) + sqrt((c * a) / b);
	result *= 4;

	printf("%lld\n", result);
	return 0;
}