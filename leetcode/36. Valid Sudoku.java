import java.util.HashSet;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < board.length; ++i) {
            HashSet<Character> rows = new HashSet<>();
            HashSet<Character> cols = new HashSet<>();

            for (int j = 0; j < board[0].length; ++j) {
                if (rows.contains(board[i][j]) || cols.contains(board[j][i])) {
                    return false;
                }
                if (board[i][j] != '.') {
                    rows.add(board[i][j]);
                }
                if (board[j][i] != '.') {
                    cols.add(board[j][i]);
                }
            }
        }

        for (int boxX = 0; boxX < 3; ++boxX) {
            for (int boxY = 0; boxY < 3; ++boxY) {
                HashSet<Character> boxSet = new HashSet<>();
                for (int i = boxX * 3; i < boxX * 3 + 3; ++i) {
                    for (int j = boxY * 3; j < boxY * 3 + 3; ++j) {
                        if (board[i][j] == '.') {
                            continue;
                        }
                        if (boxSet.contains(board[i][j])) {
                            return false;
                        }
                        boxSet.add(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
}
