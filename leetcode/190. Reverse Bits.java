public class Solution {
  private String inverseBitRepresentation(int n) {
    int original = n;
    n = Math.abs(original);

    String result = "";

    while (n != 0) {
      result += (n % 2 == 0 ? "0" : "1");
      n /= 2;
    }

    for (int i=result.length() - 1; i<=32; ++i) {
      result += "0";
    }

    if (original < 0) {
      StringBuilder temp = new StringBuilder(result);

      for (int i=0; i<result.length(); ++i) {
        char ch = temp.charAt(i);
        if (ch == '0') {
          temp.setCharAt(i, '1');
        } else {
          temp.setCharAt(i, '0');
        }
      }

      int counter = 1;
      for (int i = 0; i < result.length(); ++i) {
        char ch = temp.charAt(i);
        if (ch == '1' && counter == 1) {
          temp.setCharAt(i, '0');
        } else {
          temp.setCharAt(i, '1');
          break;
        }
      }

      result = temp.toString();
    }

    return result;
  }

  //
  // you need treat n as an unsigned value
  public int reverseBits(int n) {
    String inverseBits = inverseBitRepresentation(n);
    int multiplier = 1;
    int finalResult = 0;

    for (int i=0; i<inverseBits.length(); ++i) {
      char ch = inverseBits.charAt(inverseBits.length() - i - 1);
      int chInt = ch - '0';
      if (chInt == 1) {
        finalResult += multiplier;
      }
      multiplier *= 2;
    }

    return finalResult;
  }
}
