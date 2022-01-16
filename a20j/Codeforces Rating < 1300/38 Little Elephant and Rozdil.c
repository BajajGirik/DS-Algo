#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	long long int a[n];
	int lowest = 0, secondLowest = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		if (a[lowest] >= a[i])
		{
			secondLowest = lowest;
			lowest = i;
		}

		else if (a[secondLowest] > a[i])
			secondLowest = i;
	}

	if (a[lowest] == a[secondLowest] && lowest != secondLowest)
		printf("Still Rozdil\n");
	else
		printf("%d\n", lowest + 1);

	return 0;
}