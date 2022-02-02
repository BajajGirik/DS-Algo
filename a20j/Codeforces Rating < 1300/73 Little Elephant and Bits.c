#include <stdio.h>
#define MAX (long long int)1e5

int main()
{
	char s[MAX + 1];
	scanf("%s", s);

	long long int i;
	for (i = 0; s[i + 1] != '\0'; ++i)
	{
		if (s[i] == '0')
			break;

		printf("%c", s[i]);
	}

	++i;
	for (; s[i] != '\0'; ++i)
		printf("%c", s[i]);

	printf("\n");
	return 0;
}