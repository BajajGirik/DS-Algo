/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define vi                vector<ll>
#define vvi               vector<vi>
#define all(v)            v.begin(), v.end()
#define pii               pair<ll, ll>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i < b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define rloop(i, a)       for (auto i : a)
#define rrloop(i, a)      for (auto &i : a)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
/******************************************************/

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
#endif
}

void solve() {
	vector<int> freq(26, 0);
	string input;
	cin >> input;

	for(char ch: input) {
		++freq[ch - 'A'];
	}

	int indexForMid = -1;
	string leftSideOfPalindrome = "", rightSideOfPalindrome = "";
	for(int i=0; i<26; ++i) {
		if(freq[i]&1) {
			if(indexForMid != -1) {
				cout << "NO SOLUTION";
				return;
			}
			indexForMid = i;
		}

		string temp = "";
		for(int j=0; j<freq[i]/2; ++j) {
			temp += ('A' + i);
		}

		leftSideOfPalindrome = temp + leftSideOfPalindrome;
		rightSideOfPalindrome = rightSideOfPalindrome + temp;
	}

	string palindrome;
	if(indexForMid != -1) {
		palindrome = leftSideOfPalindrome + char('A' + indexForMid) + rightSideOfPalindrome;
	} else {
		palindrome = leftSideOfPalindrome + rightSideOfPalindrome;
	}

	cout << palindrome << endl;
}

int main () {
	clock_t start = clock();
	file_i_o();
	int T=1;
	// cin >> T;
	while (T--) {
		solve();
	}
	#ifndef ONLINE_JUDGE
		clock_t end = clock();
		cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
		<< " sec";
	#endif
	return 0;
}