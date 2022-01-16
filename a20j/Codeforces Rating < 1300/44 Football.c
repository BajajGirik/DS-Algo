#include <stdio.h>
#include <string.h>

int main()
{
	int n, teamA = 0, teamB = 0, flag = 0;
	scanf("%d", &n);

	char a[11], b[11];
	scanf("%s", a);
	teamA++;

	for (int i = 1; i < n; i++)
	{
		char temp[11];
		scanf("%s", temp);

		if (strcmp(a, temp) != 0)
		{
			flag == 0 && strcpy(b, temp);
			teamB++;
			flag = 1;
		}

		else
			teamA++;
	}

	if (teamA > teamB)
		printf("%s\n", a);
	else
		printf("%s\n", b);

	return 0;
}