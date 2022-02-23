#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int input[n];
	int positive = -1, negative = 1, a[n], index = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &input[i]);

		if (input[i] > 0 && positive == -1)
			positive = input[i];
		else if (input[i] < 0 && negative == 1)
			negative = input[i];
		else
			a[index++] = input[i];
	}

	if (positive > 0)
	{
		printf("1 %d\n", negative);
		printf("1 %d\n", positive);
	}
	else
	{
		positive = -1;
		negative = 1;
		index = 0;
		for (int i = 0; i < n; ++i)
		{
			if (input[i] < 0 && negative == 1)
			{
				negative = input[i];
				printf("1 %d\n", negative);
			}
			else if (input[i] < 0 && positive != 1)
			{
				if (positive == -1)
					printf("2 %d", input[i]);
				else
					printf(" %d\n", input[i]);

				++positive;
			}
			else
				a[index++] = input[i];
		}
	}
	printf("%d", index);
	for (int i = 0; i < index; ++i)
		printf(" %d", a[i]);

	printf("\n");
	return 0;
}