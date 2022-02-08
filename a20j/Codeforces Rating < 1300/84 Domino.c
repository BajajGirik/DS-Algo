#include<stdio.h>

int main()
{
	int n, sumx = 0, sumy = 0, count = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		int tempx, tempy;
		scanf("%d %d", &tempx, &tempy);

		sumx += tempx;
		sumy += tempy;

		if(tempx%2 != tempy%2)
			++count;
	}

	if(sumx%2 == 0 && sumy%2 == 0)
		printf("0\n");
	else if(sumx%2 != sumy%2 || count == 0)
		printf("-1\n");
	else
		printf("1\n");

	return 0;
}
