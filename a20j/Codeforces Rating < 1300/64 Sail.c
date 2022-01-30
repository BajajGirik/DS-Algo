#include <stdio.h>
#define ll long long int

int main()
{
	ll t, sx, sy, ex, ey;
	scanf("%lld %lld %lld %lld %lld", &t, &sx, &sy, &ex, &ey);

	char str[t + 1];
	scanf("%s", str);

	for (ll i = 0; i < t; i++)
	{
		if (ex - sx > 0 && str[i] == 'E')
			sx++;
		else if (ex - sx < 0 && str[i] == 'W')
			sx--;

		else if (ey - sy > 0 && str[i] == 'N')
			sy++;
		else if (ey - sy < 0 && str[i] == 'S')
			sy--;

		if (ex == sx && ey == sy)
		{
			printf("%lld\n", i + 1);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}