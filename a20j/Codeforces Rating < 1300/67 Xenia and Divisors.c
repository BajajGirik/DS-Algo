#include <stdio.h>

int main()
{
	long long int n;
	scanf("%lld", &n);

	long long int a[7] = {0};
	for (long long int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		++a[temp - 1];
	}

	// (a[1] + a[2] == a[3] + a[5] == a[0] && a[0] + a[1] + a[2] + a[3] + a[5] == n)
	if (!(a[1] + a[2] == a[3] + a[5] && a[1] >= a[3] && a[3] + a[5] == a[0] && a[0] == n / 3))
	{
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < n / 3; i++)
	{

		int temp1, temp2;
		if (a[1] != 0 && a[3] != 0)
		{
			temp1 = 2;
			temp2 = 4;
		}

		else if (a[1] != 0 && a[3] == 0)
		{
			temp1 = 2;
			temp2 = 6;
		}
		else
		{
			temp1 = 3;
			temp2 = 6;
		}
		printf("1 %d %d\n", temp1, temp2);
		--a[temp1 - 1];
		--a[temp2 - 1];
	}

	return 0;
}

// 1 -> 2-7
// 2 -> {4, 6}
// 3 --> {6}
// 4 --> {}
// 5 --> {} Not Needed
// 6 --> {}
// 7 --> {} Not Needed