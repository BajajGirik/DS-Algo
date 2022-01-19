#include <stdio.h>

int main()
{
	char s[101];
	scanf("%s", s);

	int count = 0;
	for (int i = 1; s[i] != '\0'; i++)
	{
		if (s[i] == s[i - 1])
			count++;
		else
			count = 0;

		if (count >= 6)
		{
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}