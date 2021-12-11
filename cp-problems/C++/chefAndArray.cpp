#include <iostream>
#include <map>
#include <utility>

#define ll long long int
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

using namespace std;
map<pair<ll, ll>,ll> mp;

ll findLargest(ll* arr, ll x, ll y)
{
	ll x1 = min(x,y);
	ll y1 = max(x,y);

	pair<ll, ll> key(x1,y1);
	if (mp.find(key) != mp.end())
		return mp[key];

	ll largest = arr[x1];
	for(ll i = x1+1; i<=y1; i++)
	{
		if (largest < arr[i])
			largest = arr[i];
	}	
	mp[key] = largest;
	return mp[key];
}

int main() {
	ll n;
	cin >> n;

	ll a[n];
	for(ll i =0; i<n; i++) {
		cin >> a[i];
	}
	
	ll m, x, y, sum = 0;
	cin >> m >> x >> y; 
	while(m--)
	{
		sum += findLargest(a,x,y);
		x = (x+7)%(n-1);
		y = (y+11)%n;
	}
	cout << sum<< endl;
	return 0;
}


