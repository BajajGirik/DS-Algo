#include <stdio.h>

int main()
{
	char target[] = "hello";
	char s[101];
	scanf("%s", s);

	int index = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == target[index])
			index++;

		if (index == 5)
		{
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}