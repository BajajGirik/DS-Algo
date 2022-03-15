/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
#define pii pair<ll, ll>
#define pb push_back
#define mp make_pair
#define mid(l, h) ((l + h) / 2)
#define loop(i, a, b) for (auto i = a; i < b; ++i)
#define looprev(i, a, b) for (auto i = a; i >= b; --i)
#define mod 1'000'000'007
#define endl '\n'
#define ff first
#define ss second
#define pinf LLONG_MAX
#define ninf LLONG_MIN
#define minim(a, b) a > b ? b : a
#define maxim(a, b) a > b ? a : b
/******************************************************/

void file_i_o()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
	ll x, a, b, c;
	cin >> x >> a >> b >> c;
	ll min, sec_min;

	if (a >= b && a >= c)
	{
		min = minim(b, c);
		sec_min = maxim(b, c);
	}
	else if (b >= a && b >= c)
	{
		min = minim(a, c);
		sec_min = maxim(a, c);
	}
	else
	{
		min = minim(a, b);
		sec_min = maxim(a, b);
	}
	cout << min * (x - 1) + sec_min << endl;
}

int main()
{
	clock_t start = clock();
	file_i_o();
	ll T = 1;
	cin >> T;
	while (T--)
	{
		solve();
	}
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
		 << " sec";
#endif
	return 0;
}