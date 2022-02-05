#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int b, g;
	scanf("%d %d", &b, &g);

	char s[3];

	if(b > g)
	{	
		s[0] = 'B';
		s[1] = 'G';
	}
	else
	{	
		s[0] = 'G';
		s[1] = 'B';
	}

	s[2] = '\0';
	while(b != 0 && g != 0)
	{
		printf("%s", s);
		--b; --g;
	}

	while(b--)
		printf("B");

	while(g--)
		printf("G");

	printf("\n");
	return 0;
}

