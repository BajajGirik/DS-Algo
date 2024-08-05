class Solution {
    public double myPow(double x, int n) {
      if (n == 0) {
        return 1;
      }

      if (n == -1) {
        return 1 / x;
      }

      if (n == 1) {
        return x;
      }

      double value = myPow(x, n / 2);
      value *= value;

      if (n % 2 != 0) {
        value *= n < 0 ? 1 / x : x;
      }

      return value;
    }
}

