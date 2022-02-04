#include <stdio.h>
#include <limits.h>

int main()
{

	int n,m;
	scanf("%d %d",&n, &m);
	
	int minTLcorrect=INT_MAX, maxTLcorrect=INT_MIN;
	for(int i=0; i<n;++i)
	{
		int temp;
		scanf("%d", &temp);

		if(minTLcorrect > temp)
			minTLcorrect = temp;

		if(maxTLcorrect < temp)
			maxTLcorrect = temp;
	}

	int v = 2*minTLcorrect > maxTLcorrect ? (2*minTLcorrect) : maxTLcorrect;
	int minTLwrong = INT_MAX;

	for(int i =0; i< m; ++i)
	{
		int temp;
		scanf("%d", &temp);

		if(minTLwrong > temp)
			minTLwrong = temp;
	}

	if(v >= minTLwrong)
		printf("-1\n");
	else
		printf("%d\n", v);

	return 0;
}
