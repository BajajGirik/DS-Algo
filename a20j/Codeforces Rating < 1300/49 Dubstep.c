#include <stdio.h>
#include <string.h>

int main()
{
	char s[204], res[204];
	scanf("%s", s);

	int length = strlen(s);
	int spaceInserted = 1, j = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (i <= length - 3 && (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'))
		{
			if (spaceInserted == 0)
			{
				res[j++] = ' ';
				spaceInserted = 1;
			}
			i += 2;
		}

		else
		{
			res[j++] = s[i];
			spaceInserted = 0;
		}
	}

	res[j - 1] == ' ' && (j--);
	res[j] = '\0';

	printf("%s\n", res);
	return 0;
}