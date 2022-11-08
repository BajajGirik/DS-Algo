#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<long, long>> time(n);
  for (int i = 0; i < n; ++i) {
    cin >> time[i].first >> time[i].second;
  }

  sort(time.begin(), time.end());

  multiset<long> peopleLeaveTimes;
  int maxPeople = 0;

  for (int i = 0; i < n; ++i) {
    peopleLeaveTimes.insert(time[i].second);

    auto ptr = peopleLeaveTimes.begin();

    while (peopleLeaveTimes.size() > 0 && *ptr < time[i].first) {
      peopleLeaveTimes.erase(ptr);
      ptr = peopleLeaveTimes.begin();
    }

    if (maxPeople < peopleLeaveTimes.size()) {
      maxPeople = peopleLeaveTimes.size();
    }
  }

  cout << maxPeople << "\n";
  return 0;
}
