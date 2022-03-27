#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long int a[n], b[n], cost = 0;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		copy(a, a + n, b);
		sort(a, a + n);

		multiset<int> s1, s2;
		for (int i = 0; i < n; i++)
		{
			s1.insert(a[i]);
			s2.insert(b[i]);

			if (s1 == s2)
			{
				cost += *(s1.rbegin()) - *(s1.begin());

				s1.clear();
				s2.clear();
			}
		}

		cout << cost << endl;
	}

	return 0;
}
