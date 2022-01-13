#include <stdio.h>

int main()
{
	char s[101];
	scanf("%s", s);

	int ones, twos, threes;
	ones = twos = threes = 0;

	for (int i = 0;; i += 2)
	{
		if (s[i] == '1')
			ones++;
		else if (s[i] == '2')
			twos++;
		else if (s[i] == '3')
			threes++;

		if (s[i + 1] == '\0')
			break;
	}

	int curr = 0;
	while (ones--)
	{
		if (curr == 0)
		{
			printf("1");
			curr++;
		}
		else
			printf("+1");
	}
	while (twos--)
	{
		if (curr == 0)
		{
			printf("2");
			curr++;
		}
		else
			printf("+2");
	}

	while (threes--)
	{
		if (curr == 0)
		{
			printf("3");
			curr++;
		}
		else
			printf("+3");
	}

	printf("\n");
	return 0;
}