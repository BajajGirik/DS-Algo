#include <stdio.h>

int main()
{
	int n, totalQues = 0;
	scanf("%d", &n);
	while (n--)
	{
		int a, b, c, noOfOnes = 0;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1)
			noOfOnes++;
		if (b == 1)
			noOfOnes++;
		if (c == 1)
			noOfOnes++;

		noOfOnes >= 2 && totalQues++;
	}

	printf("%d\n", totalQues);
	return 0;
}