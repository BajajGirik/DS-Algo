#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool cmp(const pair<long, long> &a, const pair<long, long> &b) {
  return a.second < b.second;
}

int main() {
  int n;
  cin >> n;

  vector<pair<long, long>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end(), cmp);

  int maxMovies = 0;
  long lastEndTime = -1;
  for (int i = 0; i < n; ++i) {
    // cout << v[i].first << " " << v[i].second << "\n";
    if (v[i].first >= lastEndTime) {
      ++maxMovies;
      lastEndTime = v[i].second;
    }
  }

  cout << maxMovies << "\n";
  return 0;
}
