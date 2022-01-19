#include <stdio.h>
#include <string.h>

int main()
{
	int k;
	scanf("%d", &k);

	int a[26] = {0};
	char s[1001];

	scanf("%s", s);

	for (int i = 0; s[i] != '\0'; i++)
	{
		int temp = s[i] - 'a';
		a[temp]++;
	}

	char res[strlen(s) / k + 1];
	int j = 0;

	for (int i = 0; i < 26; i++)
	{
		if (a[i] % k != 0)
		{
			printf("-1\n");
			return 0;
		}

		a[i] /= k;

		char temp = 'a' + i;
		while (a[i]--)
			res[j++] = temp;
	}

	res[j] = '\0';

	for (int i = 0; i < k; i++)
		printf("%s", res);

	printf("\n");
	return 0;
}