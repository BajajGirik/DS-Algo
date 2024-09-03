class Solution {
  private int[][] prefixSumY5;
  private int[][] prefixSumY2;
  private int[][] prefixSumX5;
  private int[][] prefixSumX2;

  private int getPower(int num, int powerOf) {
    int power = 0;

    while (num % powerOf == 0) {
      num = num / powerOf;
      power++;
    }

    return power;
  }

  private void printMatrix(int[][] matrix) {
    for (int i = 0; i < matrix.length; ++i) {
      for (int j = 0; j < matrix[0].length; ++j) {
        String spacing = String.valueOf(matrix[i][j]).length() > 1 ? " " : "  ";
        System.out.print(matrix[i][j] + spacing);
      }
      System.out.println();
    }

    System.out.println("*********************************************************");
    System.out.println();
    System.out.println();
  }

  public int maxTrailingZeros(int[][] grid) {
    prefixSumX2 = new int[grid.length][grid[0].length];
    prefixSumX5 = new int[grid.length][grid[0].length];
    prefixSumY2 = new int[grid.length][grid[0].length];
    prefixSumY5 = new int[grid.length][grid[0].length];

    for (int i = 0; i < grid.length; ++i) {
      for (int j = 0; j < grid[0].length; ++j) {
        int powerOf2 = getPower(grid[i][j], 2);
        int powerOf5 = getPower(grid[i][j], 5);

        prefixSumX2[i][j] = (j == 0 ? 0 : prefixSumX2[i][j - 1]) + powerOf2;
        prefixSumX5[i][j] = (j == 0 ? 0 : prefixSumX5[i][j - 1]) + powerOf5;

        prefixSumY2[i][j] = (i == 0 ? 0 : prefixSumY2[i - 1][j]) + powerOf2;
        prefixSumY5[i][j] = (i == 0 ? 0 : prefixSumY5[i - 1][j]) + powerOf5;
      }
    }

    int result = 0;

    for (int i = 0; i < grid.length; ++i) {
      for (int j = 0; j < grid[0].length; ++j) {
        int powerOf2Top = prefixSumY2[i][j];
        int powerOf5Top = prefixSumY5[i][j];

        int powerOf2Bottom = prefixSumY2[grid.length - 1][j] - (i == 0 ? 0 : prefixSumY2[i-1][j]);
        int powerOf5Bottom = prefixSumY5[grid.length - 1][j] - (i == 0 ? 0 : prefixSumY5[i-1][j]);

        int powerOf2Left = j == 0 ? 0 : prefixSumX2[i][j-1];
        int powerOf5Left = j == 0 ? 0 : prefixSumX5[i][j-1];

        int powerOf2Right = prefixSumX2[i][grid[0].length - 1] - prefixSumX2[i][j];
        int powerOf5Right = prefixSumX5[i][grid[0].length - 1] - prefixSumX5[i][j];

        result = Math.max(result, Math.min(powerOf2Top + powerOf2Left, powerOf5Top + powerOf5Left));
        result = Math.max(result, Math.min(powerOf2Top + powerOf2Right, powerOf5Top + powerOf5Right));
        result = Math.max(result, Math.min(powerOf2Bottom + powerOf2Left, powerOf5Bottom + powerOf5Left));
        result = Math.max(result, Math.min(powerOf2Bottom + powerOf2Right, powerOf5Bottom + powerOf5Right));
      }
    }

    return result;
  }
}
