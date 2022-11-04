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

long long total = 0;
string input;
bool grid[7][7] = {0};

int getVerticalChange(char ch) {
  switch (ch) {
  case 'D':
    return 1;
  case 'U':
    return -1;
  default:
    return 0;
  }
}

int getHorizontalChange(char ch) {
  switch (ch) {
  case 'R':
    return 1;
  case 'L':
    return -1;
  default:
    return 0;
  }
}

void countPossiblePaths(int pos, int x, int y) {
  // Base case 1:
  // Array index out of bounds (Moves out of grid) or
  // Visting already visited cell
  if (x < 0 || y < 0 || x > 6 || y > 6 || grid[x][y]) {
    return;
  }

  // Successfully reached the endpoint with total moves
  if (pos == input.size() && x == 0 && y == 6) {
    ++total;
    return;
  }

  // Base case 2:
  // Input string finished and couldn't reach the endpoint
  // Reached the destination before all moves were completed
  if (pos == input.size() || (x == 0 && y == 6)) {
    return;
  }

  // Base Case 3:
  // Check for cases where cannot move in right or left (As already visited
  // or a wall encountered). In that case if we have options to move up or
  // down, then the grid is divided into 2 parts and one of them cannot be
  // completely visited
  if (x + 1 <= 6 && x - 1 >= 0 && (y - 1 >= 0 ? grid[x][y - 1] : true) &&
      (y + 1 <= 6 ? grid[x][y + 1] : true) && !grid[x + 1][y] &&
      !grid[x - 1][y]) {
    return;
  }
  // Base Case 4:
  // Similar to Base Case 3
  if (y - 1 >= 0 && y + 1 <= 6 && (x - 1 >= 0 ? grid[x - 1][y] : true) &&
      (x + 1 <= 6 ? grid[x + 1][y] : true) && !grid[x][y - 1] &&
      !grid[x][y + 1]) {
    return;
  }

  grid[x][y] = true;

  if (input[pos] != '?') {
    int finalHDiff = x + getHorizontalChange(input[pos]);
    int finalVDiff = y + getVerticalChange(input[pos]);
    countPossiblePaths(pos + 1, finalHDiff, finalVDiff);
    grid[x][y] = false;
    return;
  }

  countPossiblePaths(pos + 1, x + 1, y);
  countPossiblePaths(pos + 1, x - 1, y);
  countPossiblePaths(pos + 1, x, y + 1);
  countPossiblePaths(pos + 1, x, y - 1);
  grid[x][y] = false;
}

int main() {
  clock_t start = clock();
  file_i_o();

  cin >> input;
  countPossiblePaths(0, 0, 0);
  cout << total << "\n";

#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "\n\nExecuted in: " << (double)(end - start) / double(CLOCKS_PER_SEC)
       << " sec";
#endif
  return 0;
}
