#include <stdio.h>

int main()
{
	char s[1001];
	scanf("%s", s);

	int a[26] = {0}, i;
	for (i = 0; s[i] != '\0'; i++)
	{
		a[s[i] - 'a']++;
	}

	int odd = 0;
	for (i = 0; i < 26; i++)
		if (a[i] % 2 != 0)
			odd++;

	if (odd == 0)
	{
		printf("First\n");
		return 0;
	}

	if ((odd - 1) % 2 == 0)
		printf("First\n");
	else
		printf("Second\n");

	return 0;
}

/*


*/