#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  long x;
  cin >> n >> x;

  vector<pair<long, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }

  sort(v.begin(), v.end());

  int i = 0, j = n - 1;
  while (i < j) {
    if (v[i].first + v[j].first == x) {
      cout << v[i].second << " " << v[j].second << "\n";
      return 0;
    }

    if (v[i].first + v[j].first < x) {
      ++i;
    } else {
      --j;
    }
  }

  cout << "IMPOSSIBLE\n";
  return 0;
}
