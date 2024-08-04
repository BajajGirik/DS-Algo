class Solution {
  public void rotate(int[][] matrix) {
    int n = matrix.length;
    int start = 0;

    while(start < n / 2) {
      int end = n-1-start;

      for (int i=start; i<end; ++i) {
        int temp = matrix[i][end];
        matrix[i][end] = matrix[start][i];
        matrix[start][i] = temp;
      }

      for (int i=start; i<end; ++i) {
        int temp = matrix[end][n-i-1];
        matrix[end][n-i-1] = matrix[start][i];
        matrix[start][i] = temp;
      }

      for (int i=start; i<end; ++i) {
        int temp = matrix[n-i-1][start];
        matrix[n-i-1][start] = matrix[start][i];
        matrix[start][i] = temp;
      }

      start++;
    }
  }
}

// start = 1
// end = 2
