#include <stdio.h>

int main()
{
	char c[4][4];
	for(int i = 0; i < 4; ++i)
		scanf("%s", c[i]);

	for(int i = 1; i < 4; i++)
		for(int j = 1; j < 4; ++j)
		{
			int count = 0;

			if(c[i][j] == c[i-1][j]) ++count;
			if(c[i][j] == c[i][j-1]) ++count;
			if(c[i][j] == c[i-1][j-1]) ++count;

			if(count >= 2 || count == 0)
			{
				printf("YES\n");
				return 0;
			}	
		}

	printf("NO\n");
	return 0;
}
