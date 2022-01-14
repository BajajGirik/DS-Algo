#include <stdio.h>
#include <string.h>

int main()
{
	char a[100], b[100], c[101];
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);

	if (strlen(a) + strlen(b) != strlen(c))
	{
		printf("NO\n");
		return 0;
	}

	int d[26] = {0};

	for (int i = 0; a[i] != '\0'; i++)
		d[a[i] - 'A']++;

	for (int i = 0; b[i] != '\0'; i++)
		d[b[i] - 'A']++;

	int flag = 0;
	for (int i = 0; c[i] != '\0'; i++)
	{
		d[c[i] - 'A']--;
		if (d[c[i] - 'A'] == -1)
		{
			flag = 1;
			printf("NO\n");
			break;
		}
	}

	flag == 0 && printf("YES\n");
	return 0;
}