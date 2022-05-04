/******************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll                long long
#define pb                push_back
#define mid(l, h)         ((l+h)/2)
#define loop(i, a, b)     for (auto i = a; i < b; ++i)
#define looprev(i, a, b)  for (auto i = a; i >= b; --i)
#define rloop(i, a)       for (auto i : a)
#define rrloop(i, a)      for (auto &i : a)
#define endl              '\n'
#define ff                first
#define ss                second
/******************************************************/

map<char, vector<string>> m;
map<char, vector<char>> first;
map<char, bool> isCalc;

bool isTerminal(char ch) {
	if((ch >= 'a' and ch <= 'z') or ch == '(' or ch == ')' or ch == '*' or ch == '+' or ch == '#') {
		return true;
	}

	return false;
}

vector<char> firstOf(char nonTerminal) {
	if(isCalc[nonTerminal]) {
		return first[nonTerminal];
	}

	bool hasEpsilon = false;

	rloop(k, m[nonTerminal]) {
		int index = 0;
		do {
			hasEpsilon = false;
			if(!isTerminal(k[index])) {
				bool epsilon = false;
				rrloop(i, m[k[index]]) {
					vector<char> temp = firstOf(k[index]);
					first[nonTerminal].insert(first[nonTerminal].end(), temp.begin(), temp.end());
					if(temp.back() == '#') {
						epsilon = true;
					}
				}

				if(epsilon) {
					index++;
					hasEpsilon = true;
				} else {
					index = -1;
				}
			} else if(k[index] == '#') {
				hasEpsilon = true;
				index++;
			} else {
				first[nonTerminal].pb(k[index]);
				index = -1;
			}
		} while(index != -1 and index < k[index]);
	}

	set<char> ans;
	rloop(i, first[nonTerminal]) {
		ans.insert(i);
	}

	first[nonTerminal].clear();

	rloop(i, ans) {
		first[nonTerminal].pb(i);
	}

	if(hasEpsilon) {
		first[nonTerminal].pb('#');
	}

	isCalc[nonTerminal] = true;
	return first[nonTerminal];
}

void printFirsts() {
	rloop(i, first) {
		cout << "First(" << i.ff << ") : { ";

		rloop(j, i.ss) {
			cout << j << ", ";
		}

		cout << "}" << endl;
	}
}

void file_i_o() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
#endif
}

int main () {
	file_i_o();

	string temp;

	while(cin >> temp) {
		string rhs = "";
		loop(i, 2, temp.size()) {
			rhs += temp[i];
		}

		m[temp[0]].pb(rhs);
	}

	rloop(i, m) {
		first[i.ff] = vector<char> {};
		isCalc[i.ff] = false;
	}

	rloop(i, isCalc) {
		if(!i.ss) {
			isCalc['-'] = false;
			m['-'] = vector<string> {string(1, i.ff)};
			firstOf('-');
		}
	}

	first.erase('-');
	m.erase('-');
	printFirsts();
	return 0;
}