#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	if (x1 != x2 && y1 != y2)
	{
		if (abs(x1 - x2) != abs(y1 - y2))
		{
			printf("-1\n");
			return 0;
		}
		else
			printf("%d %d %d %d\n", x1, y2, x2, y1);
	}
	else if (x1 == x2 && y1 == y2)
	{
		printf("-1\n");
		return 0;
	}
	else if (x1 == x2)
		printf("%d %d %d %d\n", x1 + y1 - y2, y1, x1 + y1 - y2, y2);
	else
		printf("%d %d %d %d\n", x1, y1 + x1 - x2, x2, y1 + x1 - x2);
	return 0;
}