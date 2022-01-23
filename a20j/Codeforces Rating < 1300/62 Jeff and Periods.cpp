#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>

#define ll long long int

using namespace std;

int main()
{
	ll n;
	cin >> n;

	set<ll> s;
	unordered_map<ll, vector<ll>> m;
	for (ll i = 0; i < n; i++)
	{
		ll temp;
		cin >> temp;

		s.insert(temp);

		if (m.find(temp) != m.end())
		{
			m.find(temp)->second.push_back(i);
			continue;
		}

		vector<ll> v;
		v.push_back(i);
		m.insert(make_pair(temp, v));
	}

	vector<pair<ll, ll>> p;
	for (auto num : s)
	{
		bool flag = true;
		ll diff = 0;
		ll prev = -1;
		for (auto i : m.find(num)->second)
		{
			if (prev == -1)
				prev = i;

			else if (diff == 0)
				diff = i - prev;

			else if (i - prev != diff)
			{
				flag = false;
				break;
			}

			prev = i;
		}

		if (flag)
			p.push_back(make_pair(num, diff));
	}

	cout << p.size() << "\n";

	for (auto pair : p)
		cout << pair.first << " " << pair.second << "\n";

	return 0;
}