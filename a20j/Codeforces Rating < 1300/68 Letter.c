#include <stdio.h>

int main()
{
	char s1[201], s2[201];
	gets(s1);
	gets(s2);

	int alphabets[52] = {0};

	for (int i = 0; s1[i] != '\0'; ++i)
	{
		if (s1[i] == ' ')
			continue;

		if (s1[i] >= 'a' && s1[i] <= 'z')
			++alphabets[s1[i] - 'a'];
		else
			++alphabets[s1[i] - 'A' + 26];
	}

	for (int i = 0; s2[i] != '\0'; ++i)
	{
		if (s2[i] == ' ')
			continue;

		int temp;

		if (s2[i] >= 'a' && s2[i] <= 'z')
			temp = s2[i] - 'a';
		else
			temp = s2[i] - 'A' + 26;

		--alphabets[temp];
		if (alphabets[temp] == -1)
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}