#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, k;
		scanf("%d %d",&n,&k);
		
		char s[n+1];
		scanf("%s",s);
		int i = k/2;
		
		char original[k+1];
		original[0] = s[i];

		int temp = 0, j;
		if(k%2 != 0)
			temp = 1;
			
		int index = 1;
		for(j=1;j<(k+1)/2;j++)
		{
			if(temp%2 == 0)
			{	
				original[index] = s[i-j];
				original[index+1] = s[i+j]; 
			}
			else
			{
				original[index] = s[i+j];
				original[index+1] = s[i-j];
			}
			index+=2;
		}

		if(temp%2 == 0)
			original[index] = s[i-j];

		for(i=0;i<k;i++)
			printf("%c",original[i]);

		for(;i<n;i++)
			printf("%c", s[i]);

		printf("\n");
	}
	return 0;
}
