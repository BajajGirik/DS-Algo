#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int temp, min, max, bravo = 0;
	scanf("%d", &temp);
	min = max = temp;

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &temp);
		if (min > temp)
		{
			min = temp;
			bravo++;
		}

		if (max < temp)
		{
			max = temp;
			bravo++;
		}
	}

	printf("%d\n", bravo);
}