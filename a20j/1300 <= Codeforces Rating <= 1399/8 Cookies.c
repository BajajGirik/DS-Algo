#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int sum = 0, even = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		sum += temp;

		if (temp % 2 == 0)
			++even;
	}

	if (sum % 2 == 0)
		printf("%d\n", even);
	else
		printf("%d\n", n - even);

	return 0;
}