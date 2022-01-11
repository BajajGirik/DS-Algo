#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	int n, next;
	scanf("%d %d", &n, &next);

	bool flag = false;
	for (int i = n + 1;; i++)
	{
		if (i > next)
			break;

		if (isPrime(i))
		{
			i == next && (flag = true);
			break;
		}
	}

	flag ? printf("YES\n") : printf("NO\n");

	return 0;
}