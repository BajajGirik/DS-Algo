import java.util.HashMap;
import java.util.Map;

class Solution {
  private int mod = 1000000007;

  private void updateMap(int num, HashMap<Integer, Integer> primeFactorization) {
    int currPowerOfTwo = 0;
    while (num % 2 == 0) {
      ++currPowerOfTwo;
      num /= 2;
    }

    if (currPowerOfTwo != 0) {
      Integer oldValue = primeFactorization.get(2);
      int _oldValue = oldValue == null ? 0 : oldValue;
      primeFactorization.put(2, _oldValue + currPowerOfTwo);
    }

    for (int i=3; i<=Math.sqrt(num); i+=2) {
      int currPower = 0;

      while (num % i == 0) {
        ++currPower;
        num /= i;
      }

      if (currPower != 0) {
        Integer oldValue = primeFactorization.get(i);
        int _oldValue = oldValue == null ? 0 : oldValue;
        primeFactorization.put(i, _oldValue + currPower);
      }
    }

    if (num > 2) {
      Integer oldValue = primeFactorization.get(num);
      int _oldValue = oldValue == null ? 0 : oldValue;
      primeFactorization.put(num, _oldValue + 1);
    }
  }

  public int valueAfterKSeconds(int n, int k) {
    HashMap<Integer, Integer> numerator = new HashMap<>();
    HashMap<Integer, Integer> denominator = new HashMap<>();

    for (int i = 1; i <= n-1; ++i) {
      updateMap(k+i, numerator);
      updateMap(i, denominator);
    }

    long result = 1;
    for (Map.Entry<Integer, Integer> set: numerator.entrySet()) {
      int key = set.getKey();
      int value = set.getValue();

      System.out.println("Key: " + key);
      System.out.println("Value: " + value);

      Integer denominatorValue = denominator.get(key);
      int _denominatorValue = denominatorValue == null ? 0 : denominatorValue;
      System.out.println("Denominator Value: " + _denominatorValue);

      for (int j = 1; j <= value - _denominatorValue; ++j) {
        result = (result * key) % mod;
      }
    }

    return (int)result;
  }
}

/**
 * a[0]k = 1
 * a[1]k = a[0] + a[1]k-1 = (k+1)
 * a[2]k = (k+1) + a[2]k-1 = (k+1) + k + (k-1) + ... + 1 = [(k+1) * (k+2) / 2]
 * a[3]k = [(k+1) * (k+2) * (k+3) / 6]
 * a[n]k = [(k+1) * (k+2) * (k+3)... * (k+n) / n!]
 */
