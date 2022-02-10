#include <stdio.h>
#include <stdlib.h>

struct contest {
	int ps;
	int pt;
};

int cmp(const void * a, const void * b)
{
	if(((struct contest *)a)->ps == ((struct contest *)b)->ps)
		return ((struct contest*)a)->pt - ((struct contest*)b)->pt;

	return ((struct contest *)b)->ps - ((struct contest *)a)->ps;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	struct contest s[n];
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &s[i].ps, &s[i].pt);

	qsort(s, n, sizeof(struct contest), cmp);

	int left = k - 2;
	int right =  k;

	while(right < n && s[right].ps == s[k-1].ps && s[right].pt == s[k-1].pt)
	   ++right;

	while(left >= 0 && s[left].ps == s[k-1].ps && s[left].pt == s[k-1].pt)
		--left;

	printf("%d\n", right - left - 1);
	return 0;
}
