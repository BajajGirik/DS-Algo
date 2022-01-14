#include <stdio.h>

int main()
{
	char a[101], b[101];
	scanf("%s", a);
	scanf("%s", b);

	int flag = 0;
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;

		if (b[i] >= 'A' && b[i] <= 'Z')
			b[i] += 32;

		if (a[i] != b[i])
		{
			flag = 1;
			a[i] - b[i] < 0 ? printf("-1\n") : printf("1\n");
			break;
		}
	}

	flag == 0 && printf("0\n");
	return 0;
}