#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char s[101];
		scanf("%s", s);

		int length = strlen(s);
		if (length > 10)
			printf("%c%d%c\n", s[0], length - 2, s[length - 1]);
		else
			printf("%s\n", s);
	}
	return 0;
}