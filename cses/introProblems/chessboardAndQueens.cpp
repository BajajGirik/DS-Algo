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

vector<string> chessBoard(8);
vector<bool> columnUsed(8, false);
vector<bool> rightDiagonal(15, false);
vector<bool> leftDiagonal(15, false);

long result = 0;

void countPossiblePlacements(int currRow) {
  if (currRow == 8) {
    ++result;
    return;
  }

  for (int i = 0; i < 8; ++i) {
    if (chessBoard[currRow][i] == '.' && !columnUsed[i] &&
        !rightDiagonal[i - currRow + 7] && !leftDiagonal[i + currRow]) {
      columnUsed[i] = true;
      rightDiagonal[i - currRow + 7] = true;
      leftDiagonal[i + currRow] = true;
      countPossiblePlacements(currRow + 1);
      columnUsed[i] = false;
      rightDiagonal[i - currRow + 7] = false;
      leftDiagonal[i + currRow] = false;
    }
  }
}

int main() {
  file_i_o();
  for (int i = 0; i < 8; ++i) {
    cin >> chessBoard[i];
  }

  countPossiblePlacements(0);
  cout << result << endl;
}
