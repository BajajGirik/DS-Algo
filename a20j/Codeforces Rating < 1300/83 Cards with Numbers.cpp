#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#define ll long long int

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll n;
	cin >> n;

	unordered_map<ll, vector<ll>> m;

	for(ll i = 0; i < 2*n; ++i)
	{
		ll temp;
		cin >> temp;
	
		auto it = m.find(temp);
		if(it != m.end())
			it->second.push_back(i+1);
		else
		{
			vector<ll> v;
		    v.push_back(i+1);
			m.insert(make_pair(temp, v));
		} 

	}

	vector<pair<ll, ll>> res;
	for(auto it: m)
	{
		if(it.second.size() % 2 != 0)
		{
			cout << "-1\n";
			return 0;
		}

		for(ll i = 0; i<it.second.size(); i+=2)
			res.push_back(make_pair(it.second[i], it.second[i+1]));
	}

	for(auto p : res)
		cout<< p.first << " " << p.second << "\n";

	return 0;
}
