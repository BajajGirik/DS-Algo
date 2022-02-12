#include <iostream>
#include <unordered_set>
#define ll long long int

int main()
{
	ll n, m;
	std::cin >> n >> m;

	ll a[n];
	for (ll i = 0; i < n; ++i)
		std::cin >> a[i];

	std::unordered_set<ll> s;
	ll distinct[n];
	for (ll i = n - 1; i >= 0; --i)
	{
		s.insert(a[i]);
		distinct[i] = s.size();
	}

	for (ll i = 0; i < m; ++i)
	{
		ll temp;
		std::cin >> temp;
		std::cout << distinct[temp - 1] << "\n";
	}

	return 0;
}