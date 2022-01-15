#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int temp, maxRounds = 0, index = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		if ((temp - 1) / m >= maxRounds)
		{
			maxRounds = (temp - 1) / m;
			index = i;
		}
	}

	printf("%d\n", index + 1);
	return 0;
}