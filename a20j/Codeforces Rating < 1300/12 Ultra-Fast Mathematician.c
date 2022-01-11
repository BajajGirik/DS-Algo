#include <stdio.h>

int main()
{
	char a[101], b[101];
	scanf("%s", a);
	scanf("%s", b);

	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			printf("1");
		else
			printf("0");
	}

	printf("\n");
	return 0;
}