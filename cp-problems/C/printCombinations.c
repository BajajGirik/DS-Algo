#include <stdio.h>

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);

	for (int i = 1; i <= n - x + 1; i++)
		for (int j = i + 1; j <= n - x + 2; j++)
		{
			printf("%d", i);

			for (int k = j; k <= j + x - 2; k++)
				printf(" %d", k);

			printf("\n");
		}

	return 0;
}

/*
n = 6
x = 3
1 2 3 4 5 6

i = 1; i <= n - x
j = i+1; j <= n-x+1
k = j; k <= j + x - 2

1 2 3
1 3 4
1 4 5
1 5 6


2 3 4
2 4 5
2 5 6

3 4 5
3 5 6

4 5 6
*/