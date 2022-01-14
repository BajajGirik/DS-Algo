#include <stdio.h>
#include <unordered_set>
using namespace std;

int main()
{
	long long int n;
	unordered_set<long long int> s;

	for (long long int i = 0; i < 4; i++)
	{
		scanf("%lld", &n);
		s.insert(n);
	}

	int res = 4 - s.size();
	printf("%d\n", res);
}