#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long> v;
  for (int i = 0; i < n; ++i) {
    long temp;
    cin >> temp;
    if (v.size() == 0) {
      v.push_back(temp);
      continue;
    }

    auto it = upper_bound(v.begin(), v.end(), temp);
    if (it == v.end()) {
      v.push_back(temp);
      continue;
    }

    *it = temp;
  }

  cout << v.size() << "\n";
  return 0;
}
