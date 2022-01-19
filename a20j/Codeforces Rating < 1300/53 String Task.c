#include <stdio.h>

int main()
{
	char s[101];
	scanf("%s", s);

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;

		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i')
			continue;

		printf(".%c", s[i]);
	}

	printf("\n");
	return 0;
}