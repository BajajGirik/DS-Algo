#include <stdio.h>

int main()
{
	int nums[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
	int n;
	scanf("%d", &n);

	for (int i = 0; i < 14; ++i)
	{
		if (nums[i] > n)
		{
			printf("NO\n");
			return 0;
		}

		if (n % nums[i] == 0)
		{
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}