#include <stdio.h>
#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b

void calcNext(long long int *x, long long int *y, long long int N)
{
	*x = (*x + 7) % (N - 1);
	*y = (*y + 11) % N;
}

int main()
{
	long long int n;
	scanf("%lld", &n);

	long long int a[n];
	for (long long int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	long long int map[n][n];
	for(long long int i=0;i<n;i++)
	{   map[i][i] = a[i];
		for(long long int j=i+1; j<n;j++)
		{
			if(a[j] > map[i][j-1])
				map[i][j] = a[j];
			else
				map[i][j] = map[i][j-1];		
		}
	}	

	long long int m, x1, y1;
	scanf("%lld %lld %lld", &m, &x1, &y1);

	long long int sum = 0;
	while (m--)
	{
		sum += map[min(x1,y1)][max(x1,y1)];
		calcNext(&x1, &y1, n);
	}
	printf("%lld\n", sum);

	return 0;
}

