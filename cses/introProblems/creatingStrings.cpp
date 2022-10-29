#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void file_i_o() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int main() {
  file_i_o();
  string s;
  cin >> s;

  sort(s.begin(), s.end());
  vector<string> v;
  do {
    v.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << "\n";
  }
}
