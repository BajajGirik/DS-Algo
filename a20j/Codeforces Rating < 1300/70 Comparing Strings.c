#include <stdio.h>
#include <string.h>
#define MAX 1000001

int main()
{
	char s1[MAX], s2[MAX];
	fgets(s1, MAX, stdin);
	fgets(s2, MAX, stdin);

	long long int len1 = strlen(s1);
	long long int len2 = strlen(s2);

	if (len1 != len2)
	{
		printf("NO\n");
		return 0;
	}

	long long int swap[2] = {0};
	int index = 0;

	for (long long int i = 0; i < len1; ++i)
	{
		if (s1[i] != s2[i] && index < 2)
			swap[index++] = i;
		else if (s1[i] != s2[i])
		{
			printf("NO\n");
			return 0;
		}
	}

	if (index == 2 && s1[swap[0]] == s2[swap[1]] && s1[swap[1]] == s2[swap[0]])
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}