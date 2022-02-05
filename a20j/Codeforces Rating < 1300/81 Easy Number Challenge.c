#include<stdio.h>
#include<string.h>
#define MOD 1073741824

long long int calculateNoOfDivisors(long long int x)
{
	long long int count = 0, i=1;
	while(i*i < x)
	{
		if(x % i == 0)
			count+=2;

		++i;
	}

	if(x == i*i)
		++count;

	return count;
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	long long int d[a*b*c + 1], total = 0;
	memset(d, -1, (a*b*c+1)*sizeof(d[0]));

	for(int i = 1; i<=a; ++i)
	{
		for(int j = 1; j<=b; ++j)
		{
			for(int k = 1; k<=c; ++k)
			{
				if(d[i*j*k] == -1)
					d[i*j*k]=calculateNoOfDivisors(i*j*k);	

				total += d[i*j*k];
			}
		}
	}

	printf("%lld\n", total);
	return 0;
}

/*
 * d(i, j, k) + d(i, j, k-1) + d(i, j, k-2) + ... + d(i, j, 1)
 *
 */
