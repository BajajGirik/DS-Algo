#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  set<int> m;
  int maxLen = 0;
  int start = 0;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];

    if (m.find(v[i]) != m.end()) {
      // found repetition
      if (m.size() > maxLen) {
        maxLen = m.size();
      }

      for (int j = start; j <= i; ++j) {
        m.erase(v[j]);
        if (v[j] == v[i]) {
          start = j + 1;
          break;
        }
      }
    }

    m.insert(v[i]);
  }

  if (m.size() > maxLen) {
    maxLen = m.size();
  }

  cout << maxLen << "\n";
  return 0;
}
