#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  long k;
  cin >> n >> m >> k;

  vector<long> wantedSize(n), actualSize(m);

  for (int i = 0; i < n; ++i) {
    cin >> wantedSize[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> actualSize[i];
  }

  sort(wantedSize.begin(), wantedSize.end());
  sort(actualSize.begin(), actualSize.end());

  int j = 0;
  int count = 0;
  for (int i = 0; i < n; ++i) {
    while (j < m && wantedSize[i] - k > actualSize[j]) {
      ++j;
    }

    if (j >= m) {
      break;
    }

    if (wantedSize[i] + k >= actualSize[j] &&
        wantedSize[i] - k <= actualSize[j]) {
      ++count;
      ++j;
    }
  }

  cout << count << "\n";
  return 0;
}
