#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ll long long int
#define isEven(x) x%2==0 ? true:false

ll comparator(const void* a, const void* b)
{
	return (*(ll*)b-*(ll*)a);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);

		ll a[n];
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		
		qsort(a,n,sizeof(ll),comparator);

		ll p1=a[0],p2=0;
		if (n >= 3)
			p2 = a[1]+a[2];
		else if (n>=2)
			p2 = a[1];

		for(int i=3;i<n;i++)
		{
			if (isEven(i))
				p2 += a[i];
			else
				p1 += a[i];
		}

		if(p1>p2)
			printf("first\n");
		else if(p1<p2)
			printf("second\n");
		else
			printf("draw\n");

	}
	return 0;
}
