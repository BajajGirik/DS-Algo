#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void * a, const void * b)
{
	return (*(char *)a - *(char *)b);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	char s[2*n + 1];
	scanf("%s", s);

	char s1[n], s2[n];
	for(int i=0;i<n;i++)
		s1[i] = s[i];

	for(int i = n; i<2*n; i++)
		s2[i-n] = s[i];

	qsort(s1, n ,sizeof(s1[0]), cmp);
	qsort(s2, n, sizeof(s2[0]), cmp);

	bool compareForGreater;

	if(s1[0] > s2[0])
		compareForGreater = true;
	else if(s1[0] < s2[0])
		compareForGreater = false;
	else
	{
		printf("NO\n");
		return 0;
	}

	for(int i = 1; i < n; ++i)
	{
		if((s1[i] <= s2[i] && compareForGreater) || (s1[i] >= s2[i] && !compareForGreater))
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	return 0;
}	
