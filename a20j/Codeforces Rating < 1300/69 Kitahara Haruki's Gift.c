#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int apple100 = 0, apple200 = 0;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);

		if (temp == 100)
			++apple100;
		else
			++apple200;
	}

	if (apple100 % 2 != 0 || (apple200 % 2 != 0 && apple100 < 2))
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}

// 100 100 100 100 100 200

// 200 100 100