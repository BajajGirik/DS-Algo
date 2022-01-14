#include <stdio.h>

int main()
{
	int n, total = 0;
	scanf("%d", &n);
	while (n--)
	{
		char s[4];
		scanf("%s", s);

		for (int i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == '+')
			{
				total++;
				break;
			}

			else if (s[i] == '-')
			{
				total--;
				break;
			}
		}
	}

	printf("%d\n", total);
	return 0;
}