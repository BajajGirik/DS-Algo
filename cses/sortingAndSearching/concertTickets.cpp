#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

// TLE Solution
// int main() {
//   int n, m;
//   cin >> n >> m;
//
//   vector<long> tickets(n);
//   for (int i = 0; i < n; ++i) {
//     cin >> tickets[i];
//   }
//
//   sort(tickets.begin(), tickets.end());
//
//   for (int i = 0; i < m; ++i) {
//     long maxPrice;
//     cin >> maxPrice;
//
//     auto j = lower_bound(tickets.begin(), tickets.end(), maxPrice);
//
//     if (tickets.size() == 0 || (j == tickets.begin() && maxPrice < *j)) {
//       cout << -1 << "\n";
//       continue;
//     }
//
//     if (j == tickets.end() || maxPrice < *j) {
//       --j;
//     }
//
//     cout << *j << "\n";
//     tickets.erase(j);
//   }
//
//   return 0;
// }

int main() {
  int n, m;
  cin >> n >> m;

  multiset<long, greater<long>> tickets;

  for (int i = 0; i < n; ++i) {
    long temp;
    cin >> temp;
    tickets.insert(temp);
  }

  for (int i = 0; i < m; ++i) {
    long maxPrice;
    cin >> maxPrice;

    auto ptr = tickets.lower_bound(maxPrice);
    if (ptr == tickets.end()) {
      cout << -1 << "\n";
      continue;
    }

    if (*ptr > maxPrice) {
      --ptr;
    }

    cout << *ptr << "\n";
    tickets.erase(ptr);
  }

  return 0;
}
