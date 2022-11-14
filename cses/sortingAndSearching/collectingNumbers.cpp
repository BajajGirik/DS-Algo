#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

// int main() {
//   int n;
//   cin >> n;
//
//   vector<pair<long, long>> v;
//   map<long, int> m;
//
//   long start = 0;
//   long prev = 0;
//
//   for (int i = 0; i < n; ++i) {
//     long temp;
//     cin >> temp;
//
//     if (start == 0) {
//       start = temp;
//     }
//
//     if (prev > temp) {
//       // prev is the end of the range we are keeping
//       auto it = m.lower_bound(start);
//       if (m.size() > 0 && it != m.begin()) {
//         --it;
//         int index = it->second;
//         v[index].second = prev;
//         m.erase(it);
//         m[prev] = index;
//       } else {
//         v.push_back({start, prev});
//         m[prev] = v.size() - 1;
//       }
//
//       start = temp;
//     }
//
//     prev = temp;
//   }
//
//   auto it = m.lower_bound(start);
//   if (m.size() > 0 && it != m.begin()) {
//     --it;
//     int index = it->second;
//     v[index].second = prev;
//     m.erase(it);
//     m[prev] = index;
//   } else {
//     v.push_back({start, prev});
//     m[prev] = v.size() - 1;
//   }
//
//   cout << v.size() << "\n";
//   return 0;
// }
int main() {
  int n;
  cin >> n;
  vector<long> v(n);

  for (int i = 0; i < n; ++i) {
    long temp;
    cin >> temp;

    v[temp - 1] = i;
  }

  long total = 0;
  for (int i = 1; i < n; ++i) {
    if (v[i - 1] > v[i]) {
      ++total;
    }
  }

  cout << total + 1 << "\n";
  return 0;
}

/*
6
1 4 5 2 3 6
*/

/*

 */
