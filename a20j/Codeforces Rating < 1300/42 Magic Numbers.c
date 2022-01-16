#include <stdio.h>

int main()
{
	char s[11];
	scanf("%s", s);

	int fours = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		int temp = s[i] - '0';
		if (temp == 4)
			fours++;
		else
			fours = 0;

		if ((temp != 4 && temp != 1) || fours == 3 || s[0] == '4')
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}