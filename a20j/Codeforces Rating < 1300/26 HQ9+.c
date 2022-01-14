#include <stdio.h>

int main()
{
	char s[101];
	scanf("%s", s);

	int flag = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
		{
			flag = 1;
			printf("YES\n");
			break;
		}
	}

	flag == 0 && printf("NO\n");

	return 0;
}