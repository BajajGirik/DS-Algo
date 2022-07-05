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

void handleNewPersonAndLanguages(vector<pair<vi, set<int>>> &vs, vi knownLanguages, int person) {
	bool atleastOneCommmon = false;
	pair<vi, set<int>> *base = nullptr;
	vector<pair<vi, set<int>>> updatedPersonAndLanguages;

	loop(i, 0, vs.size()) {
		pair<vi, set<int>> singleLangAndPeopleInfo = vs[i];
		bool foundCommon = false;

		rloop(kLang, knownLanguages) {
			if(singleLangAndPeopleInfo.ss.find(kLang) != singleLangAndPeopleInfo.ss.end()) {
				if(atleastOneCommmon) {
				  rloop(kLang, knownLanguages)
					(*base).ss.insert(kLang);

				} else {
				  singleLangAndPeopleInfo.ff.pb(person);
				  rloop(kLang, knownLanguages)
					singleLangAndPeopleInfo.ss.insert(kLang);
				
				  base = &singleLangAndPeopleInfo;
				  updatedPersonAndLanguages.pb(*base);
				}
				foundCommon = true;
				atleastOneCommmon = true;
				break;
			}
		}

		if(!foundCommon) {
			updatedPersonAndLanguages.pb(singleLangAndPeopleInfo);
		}
	}

	if(!atleastOneCommmon) {
		set<int> commonKnownLanguages;
		rloop(kLang, knownLanguages) {
			commonKnownLanguages.insert(kLang);
		}

		updatedPersonAndLanguages.pb(mp(vi{ person }, commonKnownLanguages));
	}

	vs = updatedPersonAndLanguages;
}

void solve() {
	int n, m;
	cin >> n >> m;

	// vector of pairs. 
	// PAIR.first represents array of people
	// PAIR.second represents set of languages these people have in commmon
	// vector of these pairs will be disjoint!
	vector<pair<vi, set<int>>> vs;
	bool atleastOneCanSpeak = false;

	loop(i, 0, n) {
		int noOfLang;
		cin >> noOfLang;
		if(noOfLang > 0)
			atleastOneCanSpeak = true;

		vi languagesKnown(noOfLang);
		loop(j, 0, noOfLang) {
			cin >> languagesKnown[j];
		}
		handleNewPersonAndLanguages(vs, languagesKnown, i);
	}

	cout << (atleastOneCanSpeak ? vs.size() - 1 : vs.size()) << endl;
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
