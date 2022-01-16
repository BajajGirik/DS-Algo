#include <stdio.h>
#include <string.h>

int main()
{
	char a[101], b[101];
	scanf("%s", a);
	scanf("%s", b);

	int length = strlen(a);
	if (length != strlen(b))
	{
		printf("NO\n");
		return 0;
	}

	for (int i = 0; i < length; i++)
	{
		if (a[i] != b[length - 1 - i])
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}