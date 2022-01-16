#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int temp, fives = 0, zeros = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);

		if (temp == 5)
			fives++;
		else
			zeros++;
	}

	if (zeros == 0)
	{
		printf("-1\n");
		return 0;
	}

	fives /= 9;
	if (fives == 0)
	{
		printf("0\n");
		return 0;
	}

	for (int i = 1; i <= fives; i++)
		printf("555555555");

	for (int i = 1; i <= zeros; i++)
		printf("0");

	printf("\n");

	return 0;
}