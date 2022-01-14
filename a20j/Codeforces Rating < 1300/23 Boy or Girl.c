#include <stdio.h>

int main()
{
	char s[101];
	scanf("%s", s);
	int a[27] = {0}, unique = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		int temp = s[i] - 'a';
		a[temp]++;
		if (a[temp] == 1)
			unique++;
	}

	unique % 2 == 0 ? printf("CHAT WITH HER!\n") : printf("IGNORE HIM!\n");
	return 0;
}