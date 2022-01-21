#include <stdio.h>

char getAdjacent(char *a, int i, int j, int n)
{
	if (i >= 1 && a[(i - 1) * n + j] == 'W' || a[(i - 1) * n + j] == 'B')
		return a[(i - 1) * n + j];

	if (j >= 1 && a[i * n + j - 1] == 'W' || a[i * n + j - 1] == 'B')
		return a[i * n + j - 1];

	return 'B';
}

char switchColor(char a)
{
	return a == 'W' ? 'B' : 'W';
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	char s[n + 1][m + 1];

	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp = getAdjacent((char *)s, i, j, m + 1);
			if (s[i][j] == '-')
				printf("-");
			else
				printf("%c", switchColor(temp));

			s[i][j] = switchColor(temp);
		}

		printf("\n");
	}

	return 0;
}
