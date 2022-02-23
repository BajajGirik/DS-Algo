#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int angle;
		scanf("%d", &angle);

		if (360 % (180 - angle) == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}