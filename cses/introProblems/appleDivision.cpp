#include <climits>
#include <cmath>
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
  // a + b = S;
  // 2a - S = minimum
  int n;
  cin >> n;

  vector<long> v(n);
  long long sum = 0;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
  }

  long long minDiff = LONG_LONG_MAX;

  for (long long i = 0; i < 1 << n; ++i) {
    long long s = 0;
    for (long long j = 0; j < n; ++j) {
      if (i & 1 << j) {
        s += v[j];
      }
    }
    long long currDiff = abs(2 * s - sum);
    minDiff = min(minDiff, currDiff);
  }

  cout << minDiff << "\n";
  return 0;
}
